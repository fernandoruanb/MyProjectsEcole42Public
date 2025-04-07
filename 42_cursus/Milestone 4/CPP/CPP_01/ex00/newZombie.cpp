/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:28:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/06 21:33:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::newZombie(std::string name)
{
	std::cout << std::endl;
	std::cout << name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
	return new Zombie(name);
}
