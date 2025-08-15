/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:41:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/08/15 18:06:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_client
{
	char	buffer[90000];
	ssize_t	sent_total;
}	t_client;

typedef struct	s_server
{
	int	serverFD;
	int	port;
	int	fd_max;
	int	next_id;
	int	clients[FD_SETSIZE];
	struct sockaddr_in	addr;
	char	buffer[90000];
}	t_server;

static t_client	clientsBuffer[FD_SETSIZE];

static void     findNewMax(t_server *myServer, fd_set *active_fds);

static void     broadcast(int clientFD, t_server *myServer, fd_set *write_fds, int flag);

static void	clearBuffer(t_server *myServer)
{
	bzero(myServer->buffer, sizeof(myServer->buffer));
}

static void	initAllClients(t_server *myServer)
{
	size_t	index = 0;
	while (index < FD_SETSIZE)
	{
		myServer->clients[index] = -1;
		bzero(clientsBuffer[index].buffer, sizeof(clientsBuffer[index].buffer));
		clientsBuffer[index].sent_total = 0;
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

static void	divineEye(int clientFD, t_server *myServer, fd_set *write_fds)
{
	char	buffer[90000];

	bzero(buffer, sizeof(buffer));
	strcat(buffer, myServer->buffer);
	bzero(myServer->buffer, sizeof(myServer->buffer));
	size_t	index = 0;
	int	fd;

	while (buffer[index] != '\0')
	{
		if (buffer[index] == '\n')
		{
			strcat(myServer->buffer, clientsBuffer[clientFD].buffer);
			bzero(clientsBuffer[clientFD].buffer, sizeof(clientsBuffer[clientFD].buffer));
			broadcast(clientFD, myServer, write_fds, 2);
			bzero(myServer->buffer, sizeof(myServer->buffer));
		}
		else
		{
			char	tmp[2] = {buffer[index], '\0'};
			strcat(clientsBuffer[clientFD].buffer, tmp);
		}
		++index;
	}
}

static void	broadcast(int clientFD, t_server *myServer, fd_set *write_fds, int flag)
{
	char	msg[90000];
	int	fd;

	bzero(msg, sizeof(msg));
	if (flag == 0 || flag == 1)
	{
		if (flag == 0)
			sprintf(msg, "server: client %d just arrived\n", myServer->clients[clientFD]);
		else
			sprintf(msg, "server: client %d just left\n", myServer->clients[clientFD]);
		fd = 0;
		while (fd <= myServer->fd_max)
		{
			if (FD_ISSET(fd, write_fds) && fd != myServer->serverFD && fd != clientFD)
				send(fd, msg, strlen(msg), 0);
			++fd;
		}
	}
	else if (flag == 2)
	{
		char	*ptr = myServer->buffer;

		while (*ptr)
		{
			if (*ptr == '\n')
			{
				ssize_t	sent_total = 0;
				ssize_t	total = strlen(msg);
				sprintf(msg, "client %d: ", myServer->clients[clientFD]);
				strcat(msg, clientsBuffer[clientFD].buffer);
				fd = 0;
				while (fd <= myServer->fd_max)
				{
					if (FD_ISSET(fd, write_fds) && fd != myServer->serverFD && fd != clientFD)
					{
						sent_total = send(fd, msg, total, 0);
						if (sent_total < 0)
							continue ;
						if (sent_total < total)
						{
							clientsBuffer[fd].sent_total += sent_total;
							strcat(clientsBuffer[fd].buffer, msg);
						}
						else
						{
							send(fd, "\n", 1, 0);
							bzero(clientsBuffer[clientFD].buffer, sizeof(clientsBuffer[clientFD].buffer));
						}
					}
					++fd;
				}
			}
			else
			{
				char	tmp[2] = {*ptr, '\0'};
				strcat(msg, tmp);
			}
			++ptr;
		}
	}
	else if (flag == 3)
	{
		ssize_t sent_total = 0;
		ssize_t	total = strlen(clientsBuffer[clientFD].buffer);

		sent_total = send(clientFD, clientsBuffer[clientFD].buffer + clientsBuffer[clientFD].sent_total, total - clientsBuffer[clientFD].sent_total, 0);
		if (sent_total < 0)
			return ;
		clientsBuffer[clientFD].sent_total += sent_total;
		if (clientsBuffer[clientFD].sent_total >= total)
		{
			bzero(clientsBuffer[clientFD].buffer, sizeof(clientsBuffer[clientFD].buffer));
			clientsBuffer[clientFD].sent_total = 0;
			send(clientFD, "\n", 1, 0);
		}
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
	while(1)
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
						myServer->clients[clientFD] = myServer->next_id;
						myServer->next_id++;
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
					ssize_t	bytes = recv(fd, myServer->buffer, sizeof(myServer->buffer), 0);
					if (bytes > 0)
						divineEye(fd, myServer, &write_fds);
					else if (bytes == -1)
						continue ;
					else
					{
						FD_CLR(fd, &active_fds);
						close(fd);
						findNewMax(myServer, &active_fds);
						myServer->clients[fd] = -1;
						broadcast(fd, myServer, &write_fds, 1);
					}
				}
			}
			++fd;
		}
	}
}

static int	ft_atoi(const char *nptr, bool *err)
{
	int	result = 0;

	if (*nptr == '\0' || !checkPort(nptr))
	{
		*err = true;
		return (0);
	}
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

static void	findNewMax(t_server *myServer, fd_set *active_fds)
{
	int	fd = 0;
	int	fd_max = myServer->serverFD;

	while (fd < myServer->serverFD)
	{
		if (FD_ISSET(fd, active_fds) && fd > fd_max)
			fd_max = fd;
		++fd;
	}
	myServer->fd_max = fd_max;
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
