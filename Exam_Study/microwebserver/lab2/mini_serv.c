/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:11:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/08/11 13:33:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_server
{
	int	port;
	int	serverFD;
	char	buffer[4096];
	struct sockaddr_in	addr;
	int	fd_max;
	int	clients[FD_SETSIZE];
	int	next_id;
}	t_server;

static bool	checkPort(const char *nptr)
{
	while (*nptr)
	{
		if (*nptr < '0' || *nptr > '9')
			return (false);
		++nptr;
	}
	return (true);
}

static int	ft_atoi(const char *nptr, bool *err)
{
	int	result;

	if (*nptr == '\0' || !checkPort(nptr))
	{
		*err = true;
		return (0);
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		result += *nptr - '0';
		if (result > 65535)
		{
			*err = true;
			return (0);
		}
		++nptr;
	}
	return (result);
}

static void	connectServer(t_server *myServer)
{
	char	err[] = "Fatal error\n";

	myServer->serverFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (myServer->serverFD == -1)
	{
		write(2, err, strlen(err));
		exit(1);
	}
	myServer->addr.sin_family = AF_INET;
	myServer->addr.sin_port = (myServer->port >> 8) | ((myServer->port & 0xFF) << 8);
	myServer->addr.sin_addr.s_addr = (1 << 24) | (0 << 16) | (0 << 8) | 127;

	if (bind(myServer->serverFD, (struct sockaddr*)&myServer->addr, sizeof(myServer->addr)) < 0)
	{
		write(2, err, strlen(err));
		close(myServer->serverFD);
		exit(1);
	}

	if (listen(myServer->serverFD, FD_SETSIZE) < 0)
	{
		write(2, err, strlen(err));
		close(myServer->serverFD);
		exit(1);
	}
}

static void	initAllClients(t_server *myServer)
{
	size_t	index;

	index = 0;
	while (index < FD_SETSIZE)
	{
		myServer->clients[index] = -1;
		++index;
	}
}

static void	broadcast(int ownerFD, t_server *myServer, fd_set *active_fds, int flag)
{
	if (flag == 0)
	{
		char	msg[456];
		size_t	index = 0;
		while (index < sizeof(msg))
		{
			msg[index] = '\0';
			++index;
		}
		sprintf(msg, "server: client %d: just arrived\n", ownerFD);
		index = 0;
		while (index <= myServer->fd_max)
		{
			if (FD_ISSET(index, active_fds) && index != myServer->serverFD && index != ownerFD)
				send(index, msg, strlen(msg), 0);
			++index;
		}
	}

	else if (flag == 1)
	{
		char	msg[456];
		size_t	index = 0;
		while (index < sizeof(msg))
		{
			msg[index] = '\0';
			++index;
		}
		sprintf(msg, "server: client %d: just left\n", ownerFD);
		index = 0;
		while (index <= myServer->fd_max)
		{
			if (FD_ISSET(index, active_fds) && index != myServer->serverFD && index != ownerFD)
				send(index, msg, strlen(msg), 0);
			++index;
		}
	}
	else
	{
		char msg[9000];
		size_t	index = 0;
		while (index < sizeof(msg))
		{
			msg[index] = '\0';
			++index;
		}
		sprintf(msg, "client %d: ", ownerFD);
		char	*ptr = myServer->buffer;
		while (*ptr)
		{
			index = 0;
			char	temp;
			if (*ptr == '\0')
				temp = '\0';
			else
				temp = *(ptr + 1);
			if ((*ptr == '\\' && temp == 'n') || *ptr == '\n')
			{
				int fd = 0;
				while (fd <= myServer->fd_max)
				{
					if (FD_ISSET(fd, active_fds) && fd != myServer->serverFD && fd != ownerFD)
					{
						send(fd, msg, sizeof(msg), 0);
						send(fd, "\n", 1, 0);
					}
					++fd;
				}
				while (index < sizeof(msg))
				{
					msg[index] = '\0';
					++index;
				}
				sprintf(msg, "client %d: ", ownerFD);
				if ((*ptr == '\\' && temp == 'n') || *ptr == '\n')
					++ptr;
			}
			else
			{
				char tmp[2] = {*ptr, '\0'};
				strcat(msg, tmp);
			}
			++ptr;
		}
	}
}

static void	clearBuffer(t_server *myServer)
{
	size_t	index;

	index = 0;
	while (index < sizeof(myServer->buffer))
	{
		myServer->buffer[index] = '\0';
		++index;
	}
}

static void	findNewMax(t_server *myServer, fd_set *active_fds)
{
	size_t	fd;
	int	fd_max = myServer->serverFD;

	fd = 0;
	while (fd < FD_SETSIZE)
	{
		if (FD_ISSET(fd, active_fds) && fd > fd_max)
			fd_max = fd;
		++fd;
	}
	myServer->fd_max = fd_max;
	printf("O FD MAX: %d\n", myServer->fd_max);
}

static void	startWebService(t_server *myServer)
{
	fd_set	read_fds;
	fd_set	write_fds;
	fd_set	active_fds;
	int	clientFD;
	int	fd_max;
	int	fd;
	char	err[] = "Fatal error\n";

	FD_ZERO(&active_fds);
	FD_SET(myServer->serverFD, &active_fds);
	myServer->fd_max = myServer->serverFD;
	fd = 0;
	while (1)
	{
		fd = 0;
		read_fds = active_fds;
		write_fds = active_fds;
		if (select(myServer->fd_max + 1, &read_fds, &write_fds, NULL, NULL) < 0)
		{
			fd = 0;
			while (fd <= myServer->fd_max)
			{
				if (FD_ISSET(fd, &active_fds))
					close(fd);
				++fd;
			}
			write(2, err, strlen(err));
			exit(1);
		}
		while (fd <= myServer->fd_max)
		{
			if (FD_ISSET(fd, &read_fds))
			{
				if (fd == myServer->serverFD)
				{
					clientFD = accept(myServer->serverFD, NULL, NULL);
					if (clientFD >= 0)
					{
						myServer->clients[clientFD] = myServer->next_id;
						FD_SET(clientFD, &active_fds);
						if (clientFD > myServer->fd_max)
							myServer->fd_max = clientFD;
						myServer->next_id++;
						broadcast(clientFD, myServer, &active_fds, 0);
					}
					else
					{
						fd = 0;
						while (fd <= myServer->fd_max)
						{
							if (FD_ISSET(fd, &active_fds))
								close(fd);
							++fd;
						}
						write(2, err, strlen(err));
						exit(1);
					}
				}
				else
				{
					clearBuffer(myServer);
					ssize_t bytes = recv(fd, &myServer->buffer, sizeof(myServer->buffer) - 1, 0);
					if (bytes <= 0)
					{
						close(fd);
						FD_CLR(fd, &active_fds);
						findNewMax(myServer, &active_fds);
						broadcast(fd, myServer, &active_fds, 1);
					}
					else
					{
						myServer->buffer[bytes] = '\0';
						broadcast(fd, myServer, &active_fds, 2);
					}
				}
			}
			++fd;
		}
	}
}

int	main(int argc, char **argv)
{
	t_server	myServer;
	bool	err;

	if (argc != 2)
	{
		char	err[] = "Wrong number of arguments\n";
		write(2, err, strlen(err));
		exit(1);
	}
	err = false;
	myServer.port = ft_atoi(argv[1], &err);
	if (err == true)
	{
		char	err[] = "Fatal error\n";
		write(2, err, strlen(err));
		exit(1);
	}
	connectServer(&myServer);
	initAllClients(&myServer);
	startWebService(&myServer);
	close(myServer.serverFD);
	return (0);
}
