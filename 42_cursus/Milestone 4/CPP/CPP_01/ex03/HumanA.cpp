/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:40:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 12:46:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack(void) const
{
	std::cout << std::endl;
	std::cout << "🧔" << name << " attacks using " << "🔨" << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
	: weapon(weapon), name(name) {}

HumanA::~HumanA() {}
