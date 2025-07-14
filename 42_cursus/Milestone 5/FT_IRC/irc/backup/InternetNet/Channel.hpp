/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:26:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/13 12:06:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <set>
# include <iostream>
# include <string>
# include "Server.hpp"
# include "Client.hpp"

class Client;

class	Channel
{
	private:
		int	index;
		std::string	name;
		std::string	topic;
		std::string	password;
		int	userLimit;
		bool	inviteFlag;
		bool	topicFlag;
		std::set<int>	members;
		std::set<int>	operators;
		std::set<int>	invited;
		Channel(const Channel &other);
		Channel& operator=(const Channel &other);
	public:
		Channel(std::string name);
		~Channel(void);
		void	addNewMember(int clientFD);
		void	setChannelIndex(int index);
		int	getChannelIndex(void) const;
		void	setName(std::string name);
		void	setTopic(std::string topic);
		void	setPassWord(std::string password);
		void	setUserLimit(int userlimit);
		void	setInviteFlag(bool inviteflag);
		void	setTopicFlag(bool topicflag);
		std::string	getName(void) const;
		std::string	getTopic(void) const;
		std::string	getPassWord(void) const;
		int	getUserLimit(void) const;
		bool	getInviteFlag(void) const;
		bool	getTopicFlag(void) const;
};
std::ofstream	operator<<(std::ostream &out, const Channel &other);
#endif /* CHANNEL_HPP */
