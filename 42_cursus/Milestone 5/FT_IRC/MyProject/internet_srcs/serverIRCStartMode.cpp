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

	index = 0;
	while (index < 1024 && ircserver->fds[index].fd == -1)
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
	std::cout << LIGHT_BLUE "New Client added" << ircserver->clFD << RESET << std::endl;
}

void	serverIRCStartMode(void)
{
	t_server *ircserver = getServer();

	ircserver->timeout = -1;
	poll(ircserver->fds, ircserver->nclFD, ircserver->timeout);
	ircserver->clFD = accept(ircserver->serverIRC, (struct sockaddr *)&ircserver->client, &ircserver->client_len);
	if (ircserver->clFD != -1)
		addNewClient();
}
