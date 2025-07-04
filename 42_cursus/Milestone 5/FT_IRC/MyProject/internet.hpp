/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internet.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:04:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/04 18:59:17 by fruan-ba         ###   ########.fr       */
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
	int	opt;
}	t_server;

int	atoiIRC(const char *port, int *err);

#endif /* INTERNET_HPP */
