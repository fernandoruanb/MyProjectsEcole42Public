/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 22:05:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/14 20:20:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Bob_clap_name"), ScavTrap("Bob"), FragTrap("Bob")
{
	std::cout << "DiamondTrap empty default constructor called for " << "Bob_aleatory" << " DiamondTrap" << std::endl;
	this->energy = ScavTrap::energy;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	this->name = "Bob";
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << name << " DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap default contructor called for " << name << " DiamondTrap" << std::endl;
	this->energy = ScavTrap::energy;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	this->name = name;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << this->name << std::endl;
	std::cout << get_claptrap_name() << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment constructor called for " << name << " DiamondTrap" << std::endl;
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

std::ostream& operator<<(std::ostream &out, const DiamondTrap &other)
{
	std::cout << "DiamondTrap " << other.get_name() << " energy: ";
	out << other.get_status();
	return (out);
}
