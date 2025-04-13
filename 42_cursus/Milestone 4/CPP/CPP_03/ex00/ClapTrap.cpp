/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:10:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/12 21:48:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hit_points(10), energy(10), attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->hit_points = other.hit_points;
	this->energy = other.energy;
	this->attack_damage = other.attack_damage;
}

std::ostream& operator<<(std::ostream &out, const ClapTrap &other)
{
	out << ClapTrap.
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->hit_points = other.hit_points;
		this->energy = other.energy;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->energy <= 0)
	{
		std::cout << "ClapTrap doesn't have enough energy to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!";
	this->energy--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy <= 0)
	{
		std::cout << "The ClapTrap " << name << "doesn't have enough energy to repair itself" << std::endl;
		return ;
	}
	this->hit_points += amount;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ((this->hit_points - amount) <= 0)
	{
		this->hit_points = 0;
		return ;
	}
	this->hit_points -= amount;
}

