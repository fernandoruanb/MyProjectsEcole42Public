/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poolLab3.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:39:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/02 18:32:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <poll.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <fcntl.h>

int	serverFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
int	pipefd[2];

static void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		std::cout << "Muito obrigado por usar o nosso programa =D" << std::endl;
		close(pipefd[0]);
		close(pipefd[1]);
		close(serverFD);
		exit(1);
	}
}

int	main(void)
{
	if (pipe(pipefd) < 0)
		exit(1);
	struct pollfd	fds[3];
	fds[0].fd = STDIN_FILENO;
	fds[1].fd = pipefd[0];
	fds[2].fd = serverFD;
	fds[0].events = POLLIN;
	fds[1].events = POLLIN;
	fds[2].events = POLLIN;
	int	ret;
	ssize_t	bytes;
	char	buffer[1024];
	sockaddr_in	server;
	sockaddr_in	client;
	socklen_t	client_len;
	int	client_fd;
	char	message[] = "Olá Cliente =D";

	client_len = sizeof(client);
	signal(SIGINT, handle_signal);
	if (serverFD == -1)
	{
		std::cerr << "Erro na criação do socket" << std::endl;
		close(pipefd[0]);
		close(pipefd[1]);
		return (1);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(12345);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (bind(serverFD, (struct sockaddr *)&server, sizeof(server)) == 0)
	{
		std::cout << "Conexão estabelecida com sucesso 127.0.0.1:12345" << std::endl;
		if (listen(serverFD, 5) != 0)
		{
			std::cerr << "Error na escuta 127.0.0.1:12345" << std::endl;
			close(pipefd[0]);
			close(pipefd[1]);
			close(serverFD);
			return (1);
		}
		std::cout << "Estou escutando em 127.0.0.1:12345 =D" << std::endl;
	}
	else
	{
		std::cerr << "Error no bind" << std::endl;
		close(pipefd[0]);
		close(pipefd[1]);
		close(serverFD);
	}

	while (1)
	{
		std::cout << "Esperando uma mensagem sua" << std::endl;
		ret = poll(fds, 3, -1);

		if (ret == 0)
		{
			std::cerr << "TimeOUT" << std::endl;
			return (1);
		}
		else if (ret < 0)
		{
			std::cerr << "Error poll" << std::endl;
			close(pipefd[0]);
			close(pipefd[1]);
			return (1);
		}

		write(pipefd[1], "Hello", 6);
		if (fds[0].revents & POLLIN)
		{
			bzero(buffer, sizeof(buffer));
			bytes = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
			if (bytes > 0)
			{
				buffer[bytes] = '\0';
				std::cout << "Recebemos a mensagem do primeiro cliente" << std::endl;
				std::cout << buffer << std::endl;
			}
		}
		if (fds[1].revents & POLLIN)
		{
			bzero(buffer, sizeof(buffer));
			bytes = read(pipefd[0], buffer, sizeof(buffer) - 1);
			if (bytes > 0)
			{
				buffer[bytes] = '\0';
				std::cout << "Recebemos a mensagem do segundo cliente" << std::endl;
				std::cout << buffer << std::endl;
			}
		}
		if (fds[2].revents & POLLIN)
		{
			bzero(buffer, sizeof(buffer));
			client_fd = accept(serverFD, (struct sockaddr *)&client, &client_len);
			fcntl(client_fd, F_SETFL, O_NONBLOCK);
			bytes = recv(client_fd, buffer, sizeof(buffer), 0);
			if (bytes > 0)
			{
				std::cout << "Recebemos a mensagem do terceiro cliente" << std::endl;
				std::cout << buffer << std::endl;
				send(client_fd, message, sizeof(message), 0);
			}
			close(client_fd);
		}
	}
	return (0);
}
