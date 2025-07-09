/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:34:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/08 18:22:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <fcntl.h>
# include <signal.h>
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
		Server(void);
		struct pollfd (*fds)[1024];
		std::string	recvBuffer[1024];
		std::string	sendBuffer[1024];
		int	serverIRC;
		int	numClients;
		int	port;
		std::string	password;
		bool	*running;
	public:
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
		int	getNumberOfClients(void) const;
		struct pollfd	(&getPollFds(void))[1024];
		void	startIRCService(void);
		void	shutdownService(void);
		void	addNewClient(int clientFD);
		void	startPollFds(void);
		void	manageBuffers(int index);
		void	broadcast(int index);
		void	privmsg(int index, std::string message);
		void	chargePrivileges(int target);
		static void	handleSignal(int signal);
};
std::ofstream operator<<(std::ostream &out, const Server &other);

class	Client
{
	private:
		int	clientFD;
		bool	authenticated;
		std::string	nickname;
		std::string	username;
		std::string	realname;
		std::string	bufferIn;
		std::string	bufferOut;
		bool	isOperator;
		Client(const Client &other);
		Client& operator=(const Client &other);
	public
		Client(void);
		~Client(void);
		void	setNickName(std::string nickname);
		void	setUserName(std::string username);
		void	setRealName(std::string realname);
		void	setAuthenticated(bool authenticated);
		void	setClientFD(int clientFD);
		int	getClientFD(void) const;
		bool	getAuthenticated(void) const;
		std::string	getNickName(void) const;
		std::string	getUserName(void) const;
		std::string	getRealName(void) const;
		std::string	getBufferIn(void) const;
		std::string	getBufferOut(void) const;
		bool	getIsOperator(void) const;
};
std::ofstream operator<<(std::ostream &out, const Client &other);
#endif /* SERVER_HPP */
