/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tinybot.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:32:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/12 17:49:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tinybot.hpp"

TinyBot::TinyBot(std::string name) : energy(10)
{
	this->name = name;
}

TinyBot::~TinyBot(void) {}

TinyBot::TinyBot(const TinyBot &other)
{
	this->name = other.name;
	this->energy = other.energy;
}

TinyBot& TinyBot::operator=(const TinyBot &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->energy = other.energy;
	}
	return (*this);
}

std::string	TinyBot::get_name(void) const
{
	return (name);
}

std::ostream& operator<<(std::ostream& out, const TinyBot &other)
{
	out << other.get_name();
	return (out);
}

void	TinyBot::announce(void) const
{
	std::cout << "Olá, eu sou o TinyBot " << name << std::endl;
}

void	TinyBot::recharge_energy(void)
{
	this->energy++;
}

void	TinyBot::show_status(void) const
{
	std::cout << this->name << " has " << this->energy << " energy points" << std::endl;
}
