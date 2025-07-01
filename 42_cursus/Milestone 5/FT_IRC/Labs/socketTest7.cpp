/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socketTest7.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:45:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/01 19:12:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <poll.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int	socketTCP = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

static void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		std::cout << "Muito obrigado por usar nosso servidor IRC =D, volte sempre." << std::endl;
		close(socketTCP);
		exit(0);
	}
}

int	main(void)
{
	std::vector<pollfd> fds;
	sockaddr_in	server;
	sockaddr_in	client;
	size_t	bytes;
	socklen_t	client_len;
	char	message[] = "Olá, cliente =D\n";
	char	buffer[1024];
	int	client_fd;

	if (socketTCP == -1)
	{
		std::cerr << "Falha na criação do socket" << std::endl;
		return (1);
	}
	signal(SIGINT, handle_signal);
	client_len = sizeof(client);
	server.sin_family = AF_INET;
	server.sin_port = htons(6667);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (bind(socketTCP, (struct sockaddr *)&server, sizeof(server)) == 0)
	{
		std::cout << "A conexão com o localhost na porta 6667 foi feita com sucesso" << std::endl;
		if (listen(socketTCP, 5) == 0)
		{
			pollfd pfd;
			pfd.fd = socketTCP;
			std::cout << "MyProgram IRC está escutando na porta 6667 agora" << std::endl;
			while (1)
			{
				client_fd = accept(socketTCP, (struct sockaddr *)&client, &client_len);
				if (client_fd > 0)
				{
					pfd.events = POLLIN;
					fds.push_back(pfd);
					fcntl(client_fd, F_SETFL, O_NONBLOCK);
					bytes = recv(client_fd, buffer, sizeof(buffer), 0);
					if (bytes > 0)
					{
						buffer[bytes] = '\0';
						std::cout << buffer << std::endl;
						send(client_fd, message, sizeof(message), 0);
					}
				}
				close(client_fd);
			}
		}
		else
		{
			std::cerr << "Infelizmente, MyProgram IRC não conseguiu escutar na porta 6667" << std::endl;
			close(socketTCP);
			return (1);
		}
	}
	else
	{
		std::cerr << "O bind não funcionou D=" << std::endl;
		close(socketTCP);
		return (1);
	}
	std::cout << "Até mais =D" << std::endl;
	close(socketTCP);
	return (0);
}
