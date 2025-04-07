/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:04:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/06 21:22:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
	std::cout << std::endl;
	std::cout << "🧟zombie_aleatory:" << " BraiiiiiiinnnzzzZ...";
	this->name = "zombie_aleatory";
}

Zombie::Zombie(std::string name)
{
	std::cout << name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << std::endl;
	std::cout << "🧟The zombie " << name << " was killed successfully👮⚔️ 🧟";
}
