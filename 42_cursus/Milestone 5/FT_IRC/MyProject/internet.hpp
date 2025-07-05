/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internet.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:04:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/04 21:44:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNET_HPP
# define INTERNET_HPP

# include <iostream>
# include <signal.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include "colours.hpp"

typedef struct	s_server
{
	int	serverIRC;
	sockaddr_in	server;
	sockaddr_in	client;
	socklen_t	client_len;
	int	clFD;
	int	opt;
	bool	running;
}	t_server;

int	atoiIRC(const char *port, int *err);
t_server*	getServer(void);

#endif /* INTERNET_HPP */
