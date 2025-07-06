/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:09:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/06 12:25:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../internet.hpp"

void	broadcast(const int sender)
{
	t_server	*ircserver = getServer();
	nfds_t	index;

	index = 1;
	while (index < ircserver->nclFD)
	{
		if (ircserver->fds[index].fd == sender)
		{
			index++;
			continue ;
		}
		send(ircserver->fds[index].fd, ircserver->buffer, sizeof(ircserver->buffer), 0);
		index++;
	}
}
