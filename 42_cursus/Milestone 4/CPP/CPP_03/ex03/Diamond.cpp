/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamond.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:10:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/13 21:44:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Bob"), ScavTrap("Bob"), FragTrap("Bob");
{
	std::cout << "DiamondTrap empty default constructor called" << std::endl;
	this->energy = ScavTrap::energy;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap default contructor called" << std::endl;
	this->energy = ScavTrap::energy;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment constructor called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->energy = other.energy;
		this->hit_points = other.hit_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

std::string	DiamondTrap::get_name(void) const
{
	return (name);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	this->energy = other.energy;
	this->hit_points = other.hit_points;
	this->attack_damage = other.attack_damage;
	this->name = other.name;
}

std::ostream& DiamondTrap::operator<<(std::ostream &out, const DiamondTrap &other)
{
	out << other.get_name();
	return (out);
}
