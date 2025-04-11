/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hello_World.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:18:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/11 14:42:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELLO_WORLD_HPP
# define HELLO_WORLD_HPP

# include <iostream>

class Message
{
	private:
		std::string destination;
		std::string	message;
	public:
		Message();
		Message(std::string message);
		~Message();
		Message(const Message& other);
		Message& operator=(const Message &other);
		std::string get_message(void) const;
		void	set_message(std::string message);
};

#endif /* HELLO_WORLD_HPP */
