/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internet.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:15:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/07 18:26:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNET_HPP
# define INTERNET_HPP

class	Server
{
	private:
		int     serverIRC;
	        sockaddr_in     server;
	        sockaddr_in     client;
	        socklen_t       client_len;
	        struct pollfd   fds[1024];
	        std::string     sendBuffer[1023];
	        std::string     recvBuffer[1024];
	        nfds_t  nclFD;
	        int     clFD;
	        int     opt;
	        bool    running;
	        int     timeout;
	        std::string     clientMessage;
        	std::string     serverMessage;
        	char    buffer[513];
	        ssize_t bytes;
	
	public:
		Server(void);
		~Server(void);
		Server& operator=(const Server &other)
		Server(const Server &other);
		void	addNewClient(void);
		t_server *getServer(void);
		void	serverIRCSStartMode(void);
		void	broadcast(void);
		void	privmsg(void);
		void	broadcast(void);
		void	cleanBuffer(void);
		void	privmsg(void);
}
std::ofstream& operator<<(std::ostream &out, const Server &other);
#endif	/* INTERNET_HPP */
