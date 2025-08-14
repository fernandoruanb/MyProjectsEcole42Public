/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:12:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/08/14 15:36:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_client
{
	char	buffer[90000];
}	t_client;

typedef struct	s_server
{
	int	serverFD;
	int	port;
	struct	sockaddr_in	addr;
	int	clients[FD_SETSIZE];
	int	next_id;
	int	fd_max;
	char	buffer[90000];
}	t_server;

static t_client	clientsBuffer[FD_SETSIZE];

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

static bool	checkNewLine(t_server *myServer)
{
	size_t	index = 0;
	while (myServer->buffer[index])
	{
		if (myServer->buffer[index] == '\n')
			return (true);
		++index;
	}
	return (false);
}

static void	clearBuffer(t_server *myServer)
{
	size_t	index;
	size_t	fd = 0;

	index = 0;
	while (index < sizeof(myServer->buffer))
	{
		myServer->buffer[index] = '\0';
		++index;
	}
}

static void	findNewMax(t_server *myServer, fd_set *active_fds)
{
	int	fd;
	int	fd_max = myServer->serverFD;

	fd = 0;
	while (fd < FD_SETSIZE)
	{
		if (FD_ISSET(fd, active_fds) && fd > fd_max)
			fd_max = fd;
		++fd;
	}
	myServer->fd_max = fd_max;
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

static void	broadcast(int clientFD, t_server *myServer, fd_set *write_fds, int flag)
{
	char	msg[90000];
	size_t	index = 0;

	while (index < sizeof(msg))
	{
		msg[index] = '\0';
		++index;
	}
	if (flag == 0)
	{
		sprintf(msg, "server: client %d just arrived\n", myServer->clients[clientFD]);
		int fd = 0;
		while (fd <= myServer->fd_max)
		{
			if (FD_ISSET(fd, write_fds) && fd != myServer->serverFD && fd != clientFD)
				send(fd, &msg, strlen(msg), 0);
			++fd;
		}
	}
	else if (flag == 1)
	{
		sprintf(msg, "server: client %d just left\n", myServer->clients[clientFD]);
		int fd = 0;
		while (fd <= myServer->fd_max)
		{
			if (FD_ISSET(fd, write_fds) && fd != myServer->serverFD && fd != clientFD)
				send(fd, &msg, strlen(msg), 0);
			++fd;
		}
	}
	else
	{
		ssize_t	len;
		sprintf(msg, "client %d: ", myServer->clients[clientFD]);
		strcat(msg, clientsBuffer[clientFD].buffer);
		char	*ptr = myServer->buffer;
		while (*ptr)
		{
			char temp;
			if (*ptr == '\0')
				temp = '\0';
			else
				temp = *(ptr + 1);
			if (*ptr == '\n')
			{
				ssize_t	total = strlen(msg);
				ssize_t	sent_total = 0;
				int	fd = 0;
				while (fd <= myServer->fd_max)
				{
					if (FD_ISSET(fd, write_fds) && fd != myServer->serverFD && fd != clientFD)
					{
						sent_total = send(fd, msg, 200, 0);
						if (sent_total == -1)
							continue ;
						while (sent_total < total)
						{
							ssize_t	tmp;
							tmp = send(fd, msg + sent_total, 200, 0);
							if (tmp == -1)
								continue ;
							sent_total += tmp;
						}
						send(fd, "\n", 1, 0);
					}
					++fd;
				}
				size_t	index = 0;
				while (index < sizeof(msg))
				{
					msg[index] = '\0';
					++index;
				}
				sprintf(msg, "client %d: ", myServer->clients[clientFD]);
			}
			else
			{
				char tmp[2] = {*ptr, '\0'};
				strcat(msg, tmp);
			}
			++ptr;
		}
		bzero(&clientsBuffer[clientFD], sizeof(clientsBuffer[clientFD]));
	}
}

static void	startWebService(t_server *myServer)
{
	fd_set	read_fds;
	fd_set	write_fds;
	fd_set	active_fds;
	int	fd;

	FD_ZERO(&active_fds);
	FD_SET(myServer->serverFD, &active_fds);
	myServer->fd_max = myServer->serverFD;

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
		}
		while (fd <= myServer->fd_max)
		{
			if (FD_ISSET(fd, &read_fds))
			{
				if (fd == myServer->serverFD)
				{
					int clientFD = accept(myServer->serverFD, NULL, NULL);
					if (clientFD > 0)
					{
						myServer->clients[clientFD] = myServer->next_id;
						myServer->next_id++;
						if (clientFD > myServer->fd_max)
							myServer->fd_max = clientFD;
						FD_SET(clientFD, &active_fds);
						broadcast(clientFD, myServer, &write_fds, 0);
					}
					else
					{
						++fd;
						continue ;
					}
				}
				else
				{
					clearBuffer(myServer);
					ssize_t	bytes = recv(fd, &myServer->buffer, sizeof(myServer->buffer) - 1, 0);
					if (bytes > 0)
					{
						printf("Quantidade de bytes lidos: %zu\n", bytes);
						if (!checkNewLine(myServer))
							strcat(clientsBuffer[fd].buffer, myServer->buffer);
						else
						{
							myServer->buffer[bytes] = '\0';
							broadcast(fd, myServer, &write_fds, 2);
						}
					}
					else
					{
						close(fd);
						FD_CLR(fd, &active_fds);
						findNewMax(myServer, &active_fds);
						broadcast(fd, myServer, &write_fds, 1);
						bzero(&clientsBuffer[fd].buffer, sizeof(clientsBuffer[fd].buffer));
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
	if (err)
	{
		char err[] = "Fatal error\n";
		write(2, err, strlen(err));
		exit(1);
	}
	initAllClients(&myServer);
	myServer.next_id = 0;
	connectServer(&myServer);
	startWebService(&myServer);
	close(myServer.serverFD);
	return (0);
}
