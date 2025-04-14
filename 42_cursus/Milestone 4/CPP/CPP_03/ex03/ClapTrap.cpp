/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:10:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/14 16:15:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("aleatory_claptrap"), hit_points(10), energy(10), attack_damage(0)
{
	std::cout << "ClapTrap Empty default constructor called for " << "aleatory_claptrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy(10), attack_damage(0)
{
	std::cout << "ClapTrap Default input constructor called for " << name << " ClapTrap" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called for " << name << " ClapTrap" << std::endl;
}

std::string	ClapTrap::get_claptrap_name(void) const
{
	return (name);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called for " << name << std::endl;
	this->hit_points = other.hit_points;
	this->energy = other.energy;
	this->attack_damage = other.attack_damage;
	this->name = other.name;
}

int	ClapTrap::get_status(void) const
{
	return (this->energy);
}

std::ostream& operator<<(std::ostream &out, const ClapTrap &other)
{
	out << other.get_status();
	return (out);
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assignment called for " << name << " ClapTrap" << std::endl;
	if (this != &other)
	{
		this->hit_points = other.hit_points;
		this->energy = other.energy;
		this->attack_damage = other.attack_damage;
		this->name = other.name;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->hit_points == 0)
	{
		std::cerr << "The ClapTrap " << name << " can't attack because is died" << std::endl;
		return ;
	}
	if (this->energy <= 0)
	{
		std::cout << "ClapTrap doesn't have enough energy to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing some points of damage!" << std::endl;
	this->energy--;
	std::cout << "ClapTrap " << name << " Energy (" << this->energy << "/50)" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cerr << std::endl;
		std::cerr << "The ClapTrap... " << name << " IS DIED DEFINITELY!!!" << std::endl;
		std::cerr << "It never will repair itself!!! NOOOOOOOOOOOO!!!" << std::endl;
		std::cerr << std::endl;
		return ;
	}
	else if (this->energy <= 0)
	{
		std::cerr << std::endl;
		std::cerr << "The ClapTrap " << name << " doesn't have enough energy to repair itself" << std::endl;
		std::cerr << std::endl;
		return ;
	}
	else if (this->hit_points == 100)
	{
		std::cout << std::endl;
		std::cout << "ClapTrap " << name << " hit_points is full" << std::endl;
		return ;
	}
	else if ((this->hit_points + amount) >= 100)
	{
		std::cout << std::endl;
		std::cout << "ClapTrap " << name << " started to repair itself!!!" << std::endl;
        	std::cout << "ClapTrap " << name << "(" << this->hit_points << "/100)" << std::endl;
		this->hit_points = 100;
        	std::cout << "ClapTrap " << name << " recovers all the hit points" << std::endl;
		std::cout << "ClapTrap " << name << " Hit Points (" << this->hit_points << "/100)" << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "ClapTrap " << name << " started to repair itself!!!" << std::endl;
	std::cout << "ClapTrap " << name << "(" << this->hit_points << "/100)" << std::endl;
	std::cout << "ClapTrap " << name << " recovers " << amount << " hit points" << std::endl;
	this->hit_points += amount;
	this->energy--;
	std::cout << "ClapTrap " << name << " Hit Points (" << this->hit_points << "/100)" << std::endl;
	std::cout << "ClapTrap " << name << " Energy (" << this->energy << "/50)" << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->hit_points)
	{
		this->hit_points = 0;
		std::cerr << std::endl;
		std::cerr << "ClapTrap " << name << " takes " << amount << " Points of damage" << std::endl;
		std::cerr << "ClapTrap " << name << " is died" << std::endl;
		std::cerr << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "ClapTrap " << name << " takes " << amount << " Points of damage" << std::endl;
	this->hit_points -= amount;
	std::cout << "ClapTrap " << name << ": Hit_Points(" << this->hit_points << "/100)";
	std::cout << std::endl;
}

