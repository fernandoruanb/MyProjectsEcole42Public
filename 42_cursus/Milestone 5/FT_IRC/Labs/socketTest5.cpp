/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socketTest5.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:00:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/30 18:25:52 by fruan-ba         ###   ########.fr       */
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
	int	socketTCP;
	int	client_id;
	char	buffer[2048];
	size_t	bytes;
	socklen_t client_len;
	char	answer[] = "Olá cliente =D\n";

	socketTCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (socketTCP == -1)
	{
		std::cerr << "Erro na criação do socket" << std::endl;
		return (1);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(6667);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	client_len = sizeof(client);

	if (bind(socketTCP, (struct sockaddr *)&server, sizeof(server)) == 0)
	{
		std::cout << "A conexão com a porta 127.0.0.1:6667 ao socket foi concluída" << std::endl;
		if (listen(socketTCP, 5) == 0)
		{
			std::cout << "O programa está escutando na porta 6667" << std::endl;
			client_id = accept(socketTCP, (struct sockaddr *)&client, &client_len);
			if (client_id == -1)
			{
				std::cerr << "Error na obtenção do fd do client" << std::endl;
				close(socketTCP);
				return (1);
			}

			std::cout << "Seja bem-vindo ao nosso IRC base client " << client_id << std::endl;
			bytes = recv(client_id, buffer, sizeof(buffer), 0);
			if (bytes > 0)
			{
				buffer[bytes] = '\0';
				std::cout << buffer << std::endl;
			}
			send(client_id, answer, sizeof(answer), 0);
			close(client_id);
		}
		else
		{
			std::cerr << "Não conseguimos colocar o socket para escutar D=" << std::endl;
			close(socketTCP);
			return (1);
		}
	}
	else
	{
		std::cerr << "A conexão do socket com IP:Porta destinados falhou" << std::endl;
		close(socketTCP);
		return (1);
	}
	std::cout << "Até mais!!! =D" << std::endl;
	close(socketTCP);
	return (0);
}
