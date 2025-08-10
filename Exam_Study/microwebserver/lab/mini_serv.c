/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:17:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/08/10 11:22:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/select.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct	s_server
{
	int	serverFD;
	int	port;
	struct sockaddr_in	addr;
}	t_server;

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

static int	ft_atoi(const char *nptr, bool *err)
{
	int	index;
	int	result;

	index = 0;
	result = 0;
	if (nptr[0] == '\0' || !checkPort(nptr))
	{
		*err = true;
		return (0);
	}
	while (nptr[index] > '0' && nptr[index] < '9')
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

static void	connectServer(t_server *myServer)
{
	char	err[] = "Fatal error\n";

	myServer->serverFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (myServer->serverFD == -1)
	{
		write(2, err, strlen(err));
		exit(1);
	}
	printf("O número da porta é: %d\n", myServer->port);
	printf("O fd do server é: %d\n", myServer->serverFD);
	myServer->addr.sin_family = AF_INET;
	myServer->addr.sin_port = (myServer->port >> 8) | ((myServer->port & 0xFF) << 8);
	myServer->addr.sin_addr.s_addr = (1 << 24) | (0 << 16) | (0 << 8) | 127;

	if (bind(myServer->serverFD, (struct sockaddr*)&myServer->addr, sizeof(myServer->addr)) < 0)
	{
		printf("oi\n");
		write(2, err, strlen(err));
		close(myServer->serverFD);
		exit(1);
	}
	if (listen(myServer->serverFD, FD_SETSIZE) < 0)
	{
		printf("oi2\n");
		write(2, err, strlen(err));
		close(myServer->serverFD);
		exit(1);
	}
	write(1, "ok2\n", 4);
}

int	main(int argc, char **argv)
{
	t_server	myServer;
	char	msg[] = "Fatal error\n";
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
		write(2, msg, strlen(msg));
		exit(1);
	}
	bzero(&myServer.addr, sizeof(myServer.addr));
	connectServer(&myServer);
	//startWebServer(&myServer);
	close(myServer.serverFD);
	return (0);
}
