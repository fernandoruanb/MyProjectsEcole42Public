/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poolLab2.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:11:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/02 14:34:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <poll.h>

int	pipefd[2];

static void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		std::cout << "Muito obrigado por usar o nosso programa =D" << std::endl;
		exit(0);
	}
}

int	main(void)
{
	pipe(pipefd);
	struct pollfd	fds[2];
	fds[0].fd = STDIN_FILENO;
	fds[1].fd = pipefd[0];
	fds[0].events = POLLIN;
	fds[1].events = POLLIN;
	int	ret;
	char	buffer[1024];
	ssize_t	bytes;

	signal(SIGINT, handle_signal);
	std::cout << "Esperando você enviar alguma mensagem" << std::endl;

	while (1)
	{
		ret = poll(fds, 2, -1); // Esse segundo indica a quantidade de clientes que temos em nosso array
		if (ret == 0)
		{
			std::cerr << "TimeOUT" << std::endl; // Se passou do tempo, o nosso é infinity com o -1
			return (1);
		}
		else if (ret < 0) // Error do poll
		{
			std::cerr << "Error poll" << std::endl;
			return (1);
		}

		write(pipefd[1], "Hello", 6);
		if (fds[0].revents & POLLIN)
		{
			std::cout << "Recebemos seu input cliente 1" << std::endl;
			bytes = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
			buffer[bytes] = '\0';
			std::cout << buffer << std::endl;
		}
		
		if (fds[1].revents & POLLIN)
		{
			std::cout << "Recebemos seu input cliente 2" << std::endl;
			bytes = read(pipefd[0], buffer, sizeof(buffer) - 1);
			buffer[bytes] = '\0';
			std::cout << buffer << std::endl;
		}
	}
	return (0);
}
