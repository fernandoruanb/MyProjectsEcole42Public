/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socketTest1.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:19:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/30 12:05:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <sys/socket.h> // Isso é para funcionalidades de socket
#include <netinet/in.h> // Isso é para usar as constantes como o IPPROTO_TCp=P

int	main(void)
{
	// AF_INET -> Adress Family / INET -> Internet
	// SOCK_STREAM -> O socket é do tipo stream, ou seja, TCP
	// 0 -> compilador decide qual é o protocolo que vai usar
	// IPPROTO_TCP para TCP IPPROTO_UDP para UDP IPPROTO_ICMP para ICMP como o ping
	//stream -> fluxo de bytes contínuo. DGRAM -> datagramas são pacotes isolados, autocontido e sem garantia

	int	sockets[3];
	int	index;

	sockets[0] = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockets[1] = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	sockets[2] = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

	index = 0;
	while (index < 3)
	{
		if (sockets[index] >= 1)
		{
			printf("Socket %d criado com sucesso: FD = %d\n", index, sockets[index]);
			close(sockets[index]);
			sockets[index] = 0;
		}
		else
			printf("Erro ao criar o socket %d\n", index);
		index++;
	}
	return (0);
}
