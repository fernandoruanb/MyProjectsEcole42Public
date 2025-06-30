/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socketTest3.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:15:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/30 14:52:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int	main(void)
{
	struct	sockaddr_in server;
	int	socketTCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (socketTCP == -1)
	{
		printf("O socket falhou em ser criado\n");
		return (1);
	}
	printf("O socket foi criado com sucesso. FD = %d\n", socketTCP);
	server.sin_family = AF_INET;
	server.sin_port = htons(6667);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (bind(socketTCP, (struct sockaddr *)&server, sizeof(server)) == 0)
	{
		printf("O bind foi muito bem sucedido ao associar a porta 6667 ao localhost\n");
		if (listen(socketTCP, 5) == 0)
		{
			printf("Pode escutar a conexão com netstat ou ss agora\n");
			sleep(10);
		}
		else
		{
			printf("O listen falhou!\n");
			close(socketTCP);
			return (1);
		}
	}
	else
		printf("O bind falhou em ser criado\n");
	close(socketTCP);
	return (0);
}
