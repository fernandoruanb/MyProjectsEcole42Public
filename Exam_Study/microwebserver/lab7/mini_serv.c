/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:58:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/08/14 15:21:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct	s_client
{
	char	buffer[90000];
	size_t	sent_total;
}	t_client;

typedef struct	s_server
{
	int	serverFD;
	int	port;
	int	next_id;
	int	fd_max;
	int	clients[FD_SETSIZE];
	char	buffer[90000];
	struct sockaddr_in	addr;
}	t_server;

static t_client	clientsBuffer[FD_SETSIZE];

static void	findNewMax(t_server *myServer, fd_set *active_fds)
{
	int	fd = 0;
	int	fd_max = myServer->serverFD;

	while (fd <= myServer->fd_max)
	{
		if (FD_ISSET(fd, active_fds) && fd > fd_max)
			fd_max = fd;
		++fd;
	}
	myServer->fd_max = fd_max;
}

static bool	checkNewLine(t_server *myServer)
{
	size_t	index = 0;

	while (index < strlen(myServer->buffer))
	{
		if (myServer->buffer[index] == '\n')
			return (true);
		++index;
	}
	return (false);
}

static void	clearBuffer(t_server *myServer)
{
	size_t	index = 0;

	while (index < sizeof(myServer->buffer))
	{
		myServer->buffer[index] = '\0';
		++index;
	}
}

static void	initAllClients(t_server *myServer)
{
	size_t	index = 0;

	while (index < FD_SETSIZE)
	{
		myServer->clients[index] = -1;
		bzero(&clientsBuffer[index], sizeof(clientsBuffer[index]));
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

static int	ft_atoi(const char *nptr, bool *err)

	if (*nptr == '\0' || !checkPort(nptr))
	{
		*err = true;
		return (0);
	}
	int	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result *= 10;
		result += (*nptr - '0');
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
	if (myServer->serverFD < 0)
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
			exit(1);
		}
		while (fd <= myServer->fd_max)
		{
			if (FD_ISSET(fd, &write_fds) && clientsBuffer[fd].sent_total != 0)
				broadcast(fd, myServer, &write_fds, 3);
			if (FD_ISSET(fd, &read_fds))
			{
				if (fd == myServer->serverFD)
				{
					int	clientFD = accept(myServer->serverFD, NULL, NULL);
					if (clientFD > 0)
					{
						FD_SET(clientFD, &active_fds);
						if (clientFD > myServer->fd_max)
							myServer->fd_max = clientFD;
						clients[clientFD] = myServer->next_id;
						myServer->next_id++;
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
					ssize_t	bytes = recv(fd, 
				}
			}
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
		char	err[] = "Fatal error\n";
		write(2, err, strlen(err));
		exit(1);
	}
	initAllClients(&myServer);
	myServer.next_id = 0;
	connectServer(&myServer);
	startWebService(&myServer);
	close(myServer->serverFD);
	return (0);
}
