/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socketTestSample1.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:45:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/30 11:57:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int	main(void)
{
	int	socketTCP = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (socketTCP == -1)
	{
		printf("Erro ao criar o socket\n");
		return (1);
	}
	printf("Socket criado com sucesso. FD = %d\n", socketTCP);
	close(socketTCP);
	return (0);
}
