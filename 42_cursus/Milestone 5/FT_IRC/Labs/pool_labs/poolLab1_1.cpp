/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poolLab1_1.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:34:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/02 12:44:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <poll.h>
#include <unistd.h>
#include <iostream>

int	main(void)
{
	pollfd	fds;
	fds.fd = STDIN_FILENO;
	fds.events = POLLIN;

	std::cout << "Estamos aguardando você digitar alguma coisa" << std::endl;

	poll(&fds, 1, -1);

	if (fds.revents & POLLIN)
	{
		int	bytes;
		char	buffer[1024];

		std::cout << "Detectado um input!" << std::endl;
		bytes = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
		buffer[bytes] = '\0';
		std::cout << buffer << std::endl;
	}
	return (0);
}
