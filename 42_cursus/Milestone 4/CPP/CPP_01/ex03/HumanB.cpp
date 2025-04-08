/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:28:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 20:38:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: weapon(NULL), name(name) {}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon* weapon)
{
	this->weapon = weapon;
}

void	HumanB::attack(void) const
{
	std::cout << std::endl;
	std::cout << "🧔" << name << " attacks with their " << "🔨" << weapon->getType() << std::endl;
}
