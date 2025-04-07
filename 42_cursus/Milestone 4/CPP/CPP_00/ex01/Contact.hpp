/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:24:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 10:19:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		std::string	get_darkest_secret(void) const;
		std::string	get_phone_number(void) const;
	public:
		Contact(void);
		void	set_first_name(const std::string &name);
		void	set_last_name(const std::string &last_name);
		void	set_nickname(const std::string &nickname);
		void	set_phone_number(const std::string &phone_number);
		void	set_darkest_secret(const std::string &darkest_secret);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
};

#endif /* CONTACT_HPP */
