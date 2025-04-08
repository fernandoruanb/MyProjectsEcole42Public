/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:25:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 17:25:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie(void)
{
	std::cout << "🧟The zombie " << name << " was killed successfully.👮⚔️ 🧟" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}
