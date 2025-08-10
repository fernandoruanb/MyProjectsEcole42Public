/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:23:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/08/10 11:22:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef	struct s_server
{
	struct sockaddr_in	addr;
	int	port;
	int	serverFD;
}	t_server;

static bool	checkPort(const char *port);

static int	ft_atoi(char *nptr, bool *err)
{
	int	result;
	int	index;

	result = 0;
	index = 0;
	if (!checkPort(nptr))
	{
		*err = true;
		return (0);
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result *= 10;
		result += nptr[index] - '0';
		if (result > 65535)
		{
			*err = true;
			return (0);
		}
		++index;
	}
	return (result);
}

static bool	checkPort(const char *port)
{
	while (*port)
	{
		if (*port < '0' || *port > '9')
			return (false);
		++port;
	}
	return (true);
}

static void	connectServer(t_server	*myServer)
{
	char	err[] = "Fatal error\n";
	myServer->serverFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (myServer->serverFD == -1)
	{
		write(2, err, strlen(err));
		exit(1);
	}
	bzero(&myServer->addr, sizeof(myServer->addr));
	myServer->addr.sin_family = AF_INET;
	myServer->addr.sin_addr.s_addr = (1 << 24) | (0 << 16) | (0 << 8) | 127;
	myServer->addr.sin_port = (myServer->port >> 8) | ((myServer->port & 0xFF) << 8);
	
	if (bind(myServer->serverFD, (struct sockaddr*)&myServer->addr, sizeof(myServer->addr)) < 0)
	{
		write(2, err, strlen(err));
		exit(1);
	}
	if (listen(myServer->serverFD, FD_SETSIZE) < 0)
	{
		write(2, err, strlen(err));
		exit(1);
	}
	write(1, "ok 2\n", 5);
}

static void	startWebServer(t_server *myServer)
{
	fd_set	read_fds;
	fd_set	write_fds;
	fd_set	active_fds;
	char	err[] = "Fatal error\n";

	FD_ZERO(&active_fds);
	FD_SET(myServer->serverFD, &active_fds);
	int	fd_max = myServer->serverFD;
	int	fd;
	int	index;

	while (1)
	{
		fd = 0;
		read_fds = active_fds;
		write_fds = active_fds;
		if (select(fd_max + 1, &read_fds, &write_fds, NULL, NULL) < 0)
		{
			write(2, err, strlen(err));
			exit(1);
		}
		while (fd < fd_max)
		{
			if (FD_ISSET(fd, &read_fds))
			{
				if (fd == myServer->serverFD)
				{
					int	clientFD = accept(myServer->serverFD, NULL, NULL);
					if (clientFD >= 0)
					{
						FD_SET(clientFD, &active_fds);
						if (clientFD > fd_max)
							fd_max = clientFD;
					}
					
				}
			}
			else
			{
				char	buf[1024];
				int	bytes = recv (fd, buf, sizeof(buf), 0);
				if (bytes <= 0)
				{
					close(fd);
					FD_CLR(fd, &active_fds);
				}
				else
				{
					index = 0;
					while (index < fd_max)
					{
						if (FD_ISSET(index, &active_fds) && index != fd)
							send(index, buf, sizeof(buf), 0);
						++index;
					}
				}
			}
			++fd;
		}
	}
}

int	main(int argc, char **argv)
{
	int	port;
	bool	err;
	t_server	myServer;

	if (argc != 2)
	{
		char	message[] = "Wrong number of arguments\n";
		write(2, message, strlen(message));
		exit(1);
	}
	char	error[] = "Fatal error\n";
	err = false;
	myServer.port = ft_atoi(argv[1], &err);
	if (argv[1][0] == '\0' || err)
	{
		write(2, error, strlen(error));
		exit(1);
	}
	write(1, "ok\n", 3);
	connectServer(&myServer);
	startWebServer(&myServer);
	close(myServer.serverFD);
	return (0);
}
