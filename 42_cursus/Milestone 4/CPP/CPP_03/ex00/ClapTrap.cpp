/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:10:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 16:25:36 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("aleatory_claptrap"), hit_points(10), energy(10), attack_damage(0)
{
	std::cout << GREEN "Empty default constructor called for aleatory_claptrap" RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy(10), attack_damage(0)
{
	std::cout << RED "Default input name constructor called for " << YELLOW << name << RED " ClapTrap" << RESET << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BLUE << YELLOW << "ClapTrap" << BLUE " Destructor constructor called for " << YELLOW << name << BLUE " ClapTrap" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << BRIGHT_CYAN "ClapTrap Copy constructor called for " << YELLOW << this->name << BRIGHT_CYAN " ClapTrap" RESET << std::endl;
	this->hit_points = other.hit_points;
	this->energy = other.energy;
	this->attack_damage = other.attack_damage;
	this->name = other.name;
}

std::string	ClapTrap::get_name(void) const
{
	return (name);
}

unsigned int	ClapTrap::get_hit_points(void) const
{
	return (hit_points);
}

unsigned int	ClapTrap::get_energy(void) const
{
	return (energy);
}

unsigned int	ClapTrap::get_attack_damage(void) const
{
	return (attack_damage);
}

int	ClapTrap::get_status(void) const
{
	return (this->energy);
}

std::ostream& operator<<(std::ostream &out, const ClapTrap &other)
{
	std::cout << other.get_status() << " energy: ";
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
	std::cout << "ClapTrap " << name << " Energy (" << this->energy << "/10)" << std::endl;
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
	else if (this->hit_points == 10)
	{
		std::cout << std::endl;
		std::cout << "ClapTrap " << name << " hit_points is full" << std::endl;
		std::cout << "ClapTrap doesn't need to repair itself" << std::endl;
		return ;
	}
	else if ((this->hit_points + amount) >= 10)
	{
		std::cout << std::endl;
		std::cout << "ClapTrap " << name << " started to repair itself!!!" << std::endl;
        	std::cout << "ClapTrap " << name << "(" << this->hit_points << "/10)" << std::endl;
		this->hit_points = 10;
        	std::cout << "ClapTrap " << name << " recovers all the hit points" << std::endl;
		std::cout << "ClapTrap " << name << " Hit Points (" << this->hit_points << "/10)" << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "ClapTrap " << name << " started to repair itself!!!" << std::endl;
	std::cout << "ClapTrap " << name << "(" << this->hit_points << "/10)" << std::endl;
	std::cout << "ClapTrap " << name << " recovers " << amount << " hit points" << std::endl;
	this->hit_points += amount;
	this->energy--;
	std::cout << "ClapTrap " << name << " Hit Points (" << this->hit_points << "/10)" << std::endl;
	std::cout << "ClapTrap " << name << " Energy (" << this->energy << "/10)" << std::endl;
	std::cout << std::endl;
}

std::string	ClapTrap::get_clapTrap(void) const
{
	return (name);
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
	std::cout << "ClapTrap " << name << ": Hit_Points(" << this->hit_points << "/10)";
	std::cout << std::endl;
}
