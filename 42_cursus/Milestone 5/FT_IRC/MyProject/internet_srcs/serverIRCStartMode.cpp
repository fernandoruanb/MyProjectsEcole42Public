/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverIRCStartMode.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:12:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/05 18:12:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../internet.hpp"

static void	addNewClient(void)
{
	t_server	*ircserver = getServer();
	int	index;

	index = 1;
	while (index < 1024 && ircserver->fds[index].fd != -1)
		index++;
	if (index == 1024)
	{
		std::cerr << RED "Error: Maximum of FDs!!!" RESET << std::endl;
		return ;
	}
	ircserver->fds[index].fd = ircserver->clFD;
	ircserver->fds[index].events = POLLIN;
	fcntl(ircserver->clFD, F_SETFL, O_NONBLOCK);
	ircserver->nclFD++;
	std::cout << BRIGHT_GREEN "New Client added: " << YELLOW << ircserver->clFD << RESET << std::endl;
}

static void	cleanBuffer(void)
{
	t_server	*ircserver = getServer();
	int	index;

	index = 0;
	while (index < 512)
	{
		ircserver->buffer[index] = '\0';
		index++;
	}
}

void	serverIRCStartMode(void)
{
	int	index;
	t_server *ircserver = getServer();
	ircserver->timeout = -1;

	while (ircserver->running)
	{
		poll(ircserver->fds, ircserver->nclFD, ircserver->timeout);
		if (ircserver->running && ircserver->fds[0].revents && POLLIN)
		{
			ircserver->clFD = accept(ircserver->serverIRC, (struct sockaddr *)&ircserver->client, &ircserver->client_len);
			if (ircserver->running && ircserver->clFD != -1)
				addNewClient();
		}
		index = 1;
		while (ircserver->running && index < 1024 && ircserver->fds[index].fd != -1)
		{
			if (ircserver->fds[index].revents & POLLIN)
			{
				cleanBuffer();
				ircserver->bytes = recv(ircserver->fds[index].fd, ircserver->buffer, 512, 0);
				if (ircserver->bytes > 0)
				{
					ircserver->buffer[ircserver->bytes] = '\0';
					std::cout << BRIGHT_GREEN "Client " << YELLOW << ircserver->fds[index].fd << " " << LIGHT_BLUE << ircserver->buffer << RESET <<  std::endl;
					send(ircserver->fds[index].fd, "Olá cliente =D ", 16, 0);
				}
			}
			index++;
		}
	}
}
