/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TinyBot.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:12:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/12 19:49:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TinyBot.hpp"

TinyBot::TinyBot(std::string name) : name(name), energy(10) {}

TinyBot::~TinyBot(void) {}

TinyBot::TinyBot(const TinyBot &robot)
{
	this->name = robot.name;
	this->energy = robot.energy;
}

TinyBot&  TinyBot::operator=(const TinyBot &robot)
{
	if (this != &robot)
	{
		this->name = robot.name;
		this->energy = robot.energy;
	}
	return (*this);
}

std::string TinyBot::get_name(void) const
{
	return (name);
}

std::ostream& operator<<(std::ostream &out, const TinyBot &robot)
{
	out << robot.get_name();
	return (out);
}

void	TinyBot::show_status(void) const
{
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Energy: " << energy << std::endl;
}

void	TinyBot::recharge_energy(void)
{
	this->energy++;
}

void	TinyBot::announce(void) const
{
	std::cout << "Eu sou o Robô " << this->get_name() << " TinyBot" << std::endl;
}
