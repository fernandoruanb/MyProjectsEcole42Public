/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:34:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/15 15:46:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <map>
# include "Channel.hpp"
# include "Client.hpp"
# include <iostream>
# include <fcntl.h>
# include <signal.h>
# include <poll.h>
# include <errno.h>
# include <limits.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "colours.hpp"

#define SERVER_NAME "irc.maroto.com"

class Channel;

class	Server
{
	private:
		Server(void);
		struct pollfd (*fds)[1024];
		std::string	recvBuffer[1024];
		std::string	sendBuffer[1024];
		std::map<int, Channel*>* channels;
		std::map<int, Client*>* clients;
		int	serverIRC;
		int	numClients;
		int	numChannels;
		int	port;
		std::string	password;
		bool	*running;
		Server&	operator=(const Server &other);
		Server(const Server &other);
		void    inviteToChannel(std::string channelName, int operatorFD, int clientFD);
		bool	checkName(std::string Name);
		void	changeChannel(std::string Name, int clientFD);
		void	deleteChannel(std::string Name, int clientFD);
		void    removeOperatorPrivilegesFromEveryBody(std::string channel);
		void    createNewChannel(std::string Name, int clientFD);
		void    kickFromChannel(std::string channel, int owner, int clientFD);
		void	addNewClient(int clientFD);
		void    changeTopic(std::string channelName, int clientFD, std::string topic);
		void	startIRCService(void);
		void	manageBuffers(int index);
		void	shutdownService(void);
		void	broadcast(int index);
		void	chargePrivileges(int target);
		void	startPollFds(void);
		bool	handleClientAuthentication(std::map<int, Client*>* clients, int fd, char* buffer, int pollIndex);
		void	privmsg(int index, int sender, std::string message);
		void	init(int port, std::string password);
		int	findGoodIndex(void);
		int	atoiIRC(std::string port);
		void	PollServerRoom(void);
		void	PollInputClientMonitoring(void);
		void	PollOutMonitoring(void);
		static void	handleSignal(int signal);
	public:
		Server(std::string portCheck, std::string password);
		~Server(void);
		void	setPassword(std::string password);
		void	setPort(int Port);
		void	setIsRunning(bool signal);
		void	setServerIRC(int serverFD);
		int	getServerIRC(void) const;
		std::string	getPassword(void) const;
		int	getPort(void)	const;
		int	getNumberOfClients(void) const;
		struct pollfd	(&getPollFds(void))[1024];
};
std::ofstream operator<<(std::ostream &out, const Server &other);

#endif /* SERVER_HPP */
