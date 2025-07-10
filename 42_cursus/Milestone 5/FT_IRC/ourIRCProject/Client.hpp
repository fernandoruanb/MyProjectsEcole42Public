/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:22:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/09 23:57:31 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>
# include <set>

class	Client
{
	private:
		int				clientFD;
		int				index;
		bool			authenticated;
		bool			registered;
		bool			isOperator;
		std::string		nickname;
		std::string		username;
		std::string		realname;
		std::string		bufferIn;
		std::string		bufferOut;
		std::string		host;
		Client(const Client &other);
		Client& operator=(const Client &other);
		std::set<std::string>	channels;
		Client(void);
	public:
		Client(int clientFD);
		~Client(void);
		void			setNickName(std::string nickname);
		void			setUserName(std::string username);
		void			setRealName(std::string realname);
		void			setAuthenticated(bool authenticated);
		void			setClientFD(int clientFD);
		void			setRegistered(bool registered);
		void			setIsOperator(bool isOperator);
		void			setHost(std::string host);
		std::string		getNickName(void) const;
		std::string		getUserName(void) const;
		int				getClientFD(void) const;
		bool			getAuthenticated(void) const;
		std::string		getRealName(void) const;
		std::string&	getBufferIn(void);
		std::string&	getBufferOut(void);
		bool			getIsOperator(void) const;
		bool			getRegistered(void) const;
		std::string		getHost(void) const; // nickname!username@host
		const std::set<std::string>&	getChannels(void) const;
		void			removeChannel(std::string channel);
		void			addChannel(std::string channel);
};
std::ostream& operator<<(std::ostream &out, const Client &other);
#endif /* CLIENT_HPP */
