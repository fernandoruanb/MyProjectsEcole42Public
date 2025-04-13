/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serena.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:41:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/13 14:44:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serena.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Default input constructor called" << std::endl;
	energy = 50;
	attack_damage = 20;
	hit_points = 100;
}

ScavTrap::ScavTrap() : ClapTrap("Bob")
{
	std::cout << "Empty default constructor called" << std::endl;
	energy = 50;
	attack_damage = 20;
	hit_points = 100;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->energy = other.energy;
	this->hit_points = other.hit_points;
	this->name = other.name;
	this->attack_damage = other.attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->energy = other.energy;
		this->hit_points = other.hit_points;
		this->name = other.name;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

std::string	 ScavTrap::get_name(void) const
{
	return (name);
}

std::ostream& operator<<(std::ostream &out, const ScavTrap &other)
{
	out << other.get_name();
	return (out);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
