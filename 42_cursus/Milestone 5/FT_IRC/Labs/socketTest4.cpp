/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socketTest4.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:00:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/30 15:59:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int	main(void)
{
	struct	sockaddr_in	server;
	struct	sockaddr_in	client;
	int	socketTCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	socklen_t	client_length;
	int	client_fd;

	if (socketTCP == -1)
	{
		printf("A criação do socket TCP falhou\n");
		return (1);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(6667);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (bind(socketTCP, (struct sockaddr *)&server, sizeof(server)) == 0)
	{
		printf("Conexão criada com sucesso do socket 127.0.0.1:6667\n");
		if (listen(socketTCP, 5) == 0)
		{
			printf("Pode agora observar a escuta em 127.0.0.1:6667 com netstat ou ss\n");
			client_fd = accept(socketTCP, (struct sockaddr *)&client, &client_length);
			if (client_fd == -1)
			{
				printf("Erro na aceitação ao MyProgram\n");
				close(socketTCP);
				return (1);
			}
			printf("Cliente seja bem-vindo a MyProgram, a sua comanda é %d\n", client_fd);
			close(client_fd);
		}
		else
		{
			printf("Erro no estabelecimento da escuta 127.0.0.1:6667\n");
			close(socketTCP);
			return (1);
		}
	}
	else
	{
		printf("Error na ligação do socket com 127.0.0.1:6667\n");
		close(socketTCP);
		return (1);
	}
	printf("Até mais! =D\n");
	close(socketTCP);
	return (0);
}
