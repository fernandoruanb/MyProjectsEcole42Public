/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:26:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/06 10:03:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void	Contact::set_first_name(const std::string &first_name)
{
	_first_name = first_name;
}

void	Contact::set_last_name(const std::string &last_name)
{
	_last_name = last_name;
}

void	Contact::set_nickname(const std::string &nickname)
{
	_nickname = nickname;
}

void	Contact::set_phone_number(const std::string &phone_number)
{
	_phone_number = phone_number;
}

void	Contact::set_darkest_secret(const std::string &darkest_secret)
{
	_darkest_secret = darkest_secret;
}

std::string	Contact::get_first_name(void) const
{
	return (_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (_nickname);
}

std::string	Contact::get_phone_number(void) const
{
	return (_phone_number);
}

std::string	Contact::get_darkest_secret(void) const
{
	return (_darkest_secret);
}
