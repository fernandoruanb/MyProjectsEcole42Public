/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hello_World.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:21:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/11 14:44:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hello_World.hpp"

Message::Message(std::string message)
{
	this->destination = message;
	this->message = "(null)";
}

Message::~Message() {

	this->destination = "(null)";
	this->message = "(null)";
}

Message::Message(const Message &other)
{
	this->destination = other.destination;
}

void	Message::set_message(std::string message)
{
	this->destination = message;
}

Message& Message::operator=(const Message &other)
{
	if (this != &other)
	{
		this->destination = other.destination;
		return (*this);
	}
	return (*this);
}

std::string Message::get_message(void) const
{
	return (this->destination);
}
