/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:47:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/14 13:56:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Bob")
{
	std::cout << "FragTrap Default contructor called for " << name << " FragTrap" << std::endl;
	energy = 100;
	attack_damage = 30;
	hit_points = 100;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap input constructor called for " << name << std::endl;
	energy = 100;
	attack_damage = 30;
	hit_points = 100;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << name << " FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap copy constructor called for " << name << " FragTrap" << std::endl;
	this->name = other.name;
	this->energy = other.energy;
	this->attack_damage = other.attack_damage;
	this->hit_points = other.hit_points;
}

std::string	FragTrap::get_name(void) const
{
	return (name);
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment constructor called for " << name << " FragTrap" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->energy = other.energy;
		this->attack_damage = other.attack_damage;
		this->hit_points = other.hit_points;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " wants a high five" << std::endl;
}

std::ostream& operator<<(std::ostream &out, const FragTrap &other)
{
	out << other.get_name();
	return (out);
}
