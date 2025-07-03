/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poolLab4.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:33:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/03 18:55:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct	pollfd	fds[10];
int	socketTCP = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

static void	handle_signal(int signal)
{
	int	index;

	if (signal == SIGINT)
	{
		index = 0;
		while (index < 10)
		{
			if (fds[index].fd != -1)
				close(fds[index].fd);
			index++;
		}
		close(socketTCP);
		std::cout << "Obrigado por usar nosso serviço de IRC =D" << std::endl;
		exit(0);
	}
}

int	main(void)
{
	sockaddr_in	server;
	sockaddr_in	client;
	socklen_t	client_len;
	char	buffer[1024];
	int	client_fd;
	char	message[] = "Olá cliente =D\n";
	ssize_t	bytes;
	int	ret;
	int	opt = 1;
	int	index;
	int	nfds = 1; // Começa como 1 para marcar quantas conexões nós temos, 1 devido a termos apenas o listening do server

	if (socketTCP == -1)
	{
		std::cerr << "Erro na criação do socket" << std::endl;
		return (1);
	}
	fds[0].fd = socketTCP;
	fds[0].events = POLLIN;
	signal(SIGINT, handle_signal);
	index = 1;
	while (index < 10)
	{
		fds[index].fd = -1; // Isso é para marcar os demais como vazios;
		index++;
	}
	setsockopt(socketTCP, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)); // Isso é para podermos realizar 
	server.sin_family = AF_INET;
	server.sin_port = htons(6667);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (bind(socketTCP, (struct sockaddr *)&server, sizeof(server)) == 0)
	{
		std::cout << "Bind efetuado com sucesso unindo o socket com localhost na porta 6667" << std::endl;
		if (listen(socketTCP, 5) == 0)
		{
			std::cout << "Escutando em 127.0.0.1:6667" << std::endl;
			while (1)
			{
				ret = poll(fds, nfds, -1);
				if (ret == 0)
				{
					std::cerr << "TimeOUT" << std::endl;
					handle_signal(SIGINT);
				}
				if (ret < 0)
				{
					std::cerr << "Error!" << std::endl;
					handle_signal(SIGINT);
				}
				if (fds[0].revents & POLLIN)
				{
					index = 1;
					client_fd = accept(socketTCP, (struct sockaddr *)&client, client_len);
					while (index < 10)
					{
						if (fds[index].fd == -1)
						{
							fds[index].fd = client_fd;
							nfds++;
						}
						index++;
					}
				}
				index = 1;
				while (index < 10)
				{
					if (fds[index].fd != -1 && fds[index].revents & POLLIN)
					{
						bzero(buffer);
						bytes = recv(fds[index].fd, buffer, sizeof(buffer), 0);
						if (bytes > 0)
						{
							std::cout << "Recebemos mensagem do cliente " << fds.fd[index] << std::endl;
							buffer[bytes] = '\0';
							std::cout << buffer << std::endl;
						}
					}
					index++;
				}
			}
		}
		else
		{
			std::cerr << "O modo escuta não funcionou D=" << std::endl;
			close(socketTCP);
			return (1);
		}
	}
	else
	{
		std::cerr << "Error Fatal!!! BIND não foi configurado" << std::endl;
		close(socketTCP);
		return (1);
	}
	std::cout << "Muito obrigado por ter usado o nosso servidor de IRC =D" << std::endl;
	close(socketTCP);
	return (0);
}
