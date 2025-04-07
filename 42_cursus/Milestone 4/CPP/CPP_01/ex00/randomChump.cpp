/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/06 21:34:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::randomChump(std::string name)
{
	Zombie	MyLittleZombie(name);

	std::cout << std::endl;
	std::cout << name << ":" <<  " BraiiiiiiinnnzzzZ..." << std::endl;
}
