/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privmsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:35:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/06 13:02:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../internet.hpp"

void	privmsg(const int target, const std::string message)
{
	t_server	*ircserver = getServer();

	if (ircserver->running && target != 0 && ircserver->fds[target].fd != -1)
		send(ircserver->fds[target].fd, message.c_str(), message.size(), 0);
}
