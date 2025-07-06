/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverIRCStartMode.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:12:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/06 15:20:04 by fruan-ba         ###   ########.fr       */
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
	ircserver->fds[index].events = POLLIN | POLLOUT;
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
	nfds_t	freedom;
	t_server *ircserver = getServer();
	int	ready;
	ircserver->timeout = -1;

	while (ircserver->running)
	{
		ready = poll(ircserver->fds, ircserver->nclFD, ircserver->timeout);
		if (ready < 0)
		{
			if (errno == EINTR)
			{
				std::cout << LIGHT_BLUE "Restarting the server..." RESET << std::endl;
				continue ;
			}
			else
			{
				std::cerr << RED "Error: Stopping the server..." RESET << std::endl;
				ircserver->running = false;
				freedom = 0;
				while (freedom < ircserver->nclFD)
				{
					close(ircserver->fds[freedom].fd);
					ircserver->fds[freedom].fd = -1;
					freedom++;
				}
			}
		}
		if (ircserver->running && ircserver->fds[0].revents & POLLIN)
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
					broadcast(ircserver->fds[index].fd);
					privmsg(index - 1, "PRIVMSG HELLO");
				}
				else if (ircserver->bytes == 0)
				{
					std::cout << LIGHT_BLUE "Client " << YELLOW << ircserver->fds[index].fd << LIGHT_BLUE " disconnected" RESET << std::endl;
					close(ircserver->fds[index].fd);
					ircserver->fds[index] = ircserver->fds[ircserver->nclFD - 1];
					ircserver->fds[ircserver->nclFD - 1].fd = -1;
					ircserver->nclFD--;
				}
			}
			index++;
		}
	}
}
