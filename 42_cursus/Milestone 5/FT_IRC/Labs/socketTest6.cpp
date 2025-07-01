/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socketTest6.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:05:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/01 17:39:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int	socketTCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

static void	handle_signals(int signal)
{
	if (signal == SIGINT)
	{
		std::cout << "Muito obrigado por usar nosso server IRC =D" << std::endl;
		close(socketTCP);
		exit(0);
	}
}

int	main(void)
{
	sockaddr_in	client;
	sockaddr_in	server;
	char	buffer[100];
	char	message[] = "Oi cliente =D\n";
	socklen_t client_len = sizeof(client);
	size_t	bytes;
	int	client_fd;

	if (socketTCP == -1)
	{
		std::cerr << "Error na criação do socket TCP" << std::endl;
		return (1);
	}
	signal(SIGINT, handle_signals);
	server.sin_family = AF_INET;
	server.sin_port = htons(6667);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (bind(socketTCP, (struct sockaddr *)&server, sizeof(server)) == 0)
	{
		std::cout << "Conexão bind com sucesso 127.0.0.1:6667" << std::endl;
		if (listen(socketTCP, 5) == 0)
		{
			while (1)
			{
				std::cout << "A escuta foi aberta com sucesso 127.0.0.1:6667 (IRC)" << std::endl;
				client_fd = accept(socketTCP, (struct sockaddr *)&client, &client_len);
				if (client_fd == -1)
				{
					std::cerr << "Inválido cliente" << std::endl;
					close(socketTCP);
					return (1);
				}
				fcntl(client_fd, F_SETFL, O_NONBLOCK);
				bytes = recv(client_fd, buffer, sizeof(buffer), 0);
				if (bytes > 0)
				{
					buffer[bytes] = '\0';
					std::cout << buffer << std::endl;
					send(client_fd, message, sizeof(message), 0);
				}
				close(client_fd);
			}
		}
		else
		{
			std::cerr << "A escuta não funcionou" << std::endl;
			close(socketTCP);
			return (1);
		}
	}
	else
	{
		std::cerr << "Conexão bind não estabelecida" << std::endl;
		close(socketTCP);
		return (1);
	}
	close(socketTCP);
	std::cout << "Até mais cliente" << std::endl;
	return (0);
}
