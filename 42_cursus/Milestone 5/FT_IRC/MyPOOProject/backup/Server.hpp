/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:34:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/08 14:04:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <fcntl.h>
# include <poll.h>
# include <errno.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "colours.hpp"

class	Server
{
	private:
		int	serverIRC;
		int	port;
		std::string	password;
		bool	running;
	public:
		Server(void);
		Server(std::string portCheck, std::string password);
		~Server(void);
		Server&	operator=(const Server &other);
		Server(const Server &other);
		void	setPassword(std::string password);
		void	setPort(int Port);
		void	setIsRunning(bool signal);
		void	setServerIRC(int serverFD);
		int	getServerIRC(void) const;
		std::string	getPassword(void) const;
		int	getPort(void)	const;
		int	atoiIRC(std::string port);
		void	init(int port, std::string password);
};
std::ofstream operator<<(std::ostream &out, const Server &other);
#endif /* SERVER_HPP */
