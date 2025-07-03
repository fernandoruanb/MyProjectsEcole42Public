/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poolLab1.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:02:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/02 13:01:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <poll.h>
#include <unistd.h>
#include <iostream>

int	main(void)
{
	pollfd	pfd; // define a piscina de fds
	pfd.fd = STDIN_FILENO; // setar o fd para a entrada padrão
	pfd.events = POLLIN; // fica aguardando interação
	int	ret;

	std::cout << "Esperando você digitar algo no teclado" << std::endl;
	while (1)
	{
		ret = poll(&pfd, 1, -1); // monitora o fd 1 STDIN_FILENO e -1 aguarda eternamente
		if (ret == 0)
		{
			std::cerr << "TimeOUT" << std::endl; // Isso jamais ocorre com -1 devido que é infinity
			return (1);
		}
		else if (ret < 0)
		{
			std::cerr << "Error poll!" << std::endl;
			exit(1);
		}
	
		if (pfd.revents & POLLIN) // Verifica se o último bit foi setado
		{
			int	bytes;
			char	buffer[1024];

			std::cout << "Tem dados disponíveis no teclado" << std::endl;
			bytes = read(STDIN_FILENO, buffer, sizeof(buffer) - 1); // Já sabemos que recebemos, então, lemos.
			buffer[bytes] = '\0'; // proteção ao final do que foi lido.
			std::cout << buffer << std::endl; // Printamos o texto recebido
		}
		else
		{
			std::cout << "Nada foi recebido" << std::endl;
		}
	}
	return (0);
}
