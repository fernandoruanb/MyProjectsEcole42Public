/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socketTest2.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:32:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/30 14:31:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int	main(void)
{
	// AF_INET -> Address Family (IPv4) AF_INET6 para IPv6

	struct	sockaddr_in server;
	int	socketTCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (socketTCP == -1)
	{
		printf("Erro na criação do socket TCP\n");
		return (1);
	}
	server.sin_family = AF_INET; //IPv4, use AF_INET6 para IPv6
	server.sin_port = htons(6667); // Passo a porta, mas, ela é passada como Host To Network em forma Little Endian
	server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Aqui converte para o binário que pode ser armazenado
	if (bind(socketTCP, (struct sockaddr *)&server, sizeof(server)) == 0)
	{
		printf("Bind feito com sucesso =D\n");
		printf("10 segundos para escuta na porta 6667 usando o protocolo TCP\n");
		sleep(10);
		printf("A conexão foi encerrada D=\n");
	}
	else
	{
		printf("Bind não foi feito D=");
		close(socketTCP);
		return (1);
	}
	close(socketTCP);
	return (0);
}
