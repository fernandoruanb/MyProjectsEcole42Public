/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:56:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/14 11:15:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Default input constructor called for " << name << " ScavTrap" << std::endl;
	energy = 50;
	attack_damage = 20;
	hit_points = 100;
}

ScavTrap::ScavTrap(void) : ClapTrap("Bob")
{
	std::cout << "ScavTrap Empty default constructor called for " << "Bob_aleatory" << " ScavTrap" << std::endl;
	energy = 50;
	attack_damage = 20;
	hit_points = 100;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called for " << name << " ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap copy constructor called for " << name << " ScavTrap" << std::endl;
	this->energy = other.energy;
	this->hit_points = other.hit_points;
	this->name = other.name;
	this->attack_damage = other.attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment called for " << name << " ScavTrap" << std::endl;
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
