/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:11:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 16:23:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap c1("Bob");
	ClapTrap c2("WALL-E");
	ClapTrap c3("James");
	ClapTrap c4("Optimus");
	ClapTrap c5;
	ClapTrap c6(c1);

	std::cout << LIGHT_MAGENTA << "==============================================" RESET << std::endl;
	std::cout << YELLOW "Name: " RESET<< c1.get_name() << std::endl;
	std::cout << YELLOW "Hit Points: " RESET << c1.get_hit_points() << std::endl;
	std::cout << YELLOW "Energy: " RESET << c1.get_energy() << std::endl;
	std::cout << YELLOW "Attack_Damage: " RESET << c1.get_attack_damage() << std::endl;
	std::cout << LIGHT_MAGENTA << "==============================================" RESET << std::endl;
	c6 = c5;
	c1.attack("James");
	c3.takeDamage(7);
	c3.beRepaired(4);
	c3.attack("Bob");
	c1.takeDamage(9);
	c1.beRepaired(10);
	c5.attack("WALL-E");
	c2.takeDamage(10);
	c2.beRepaired(10);
	c2.attack(c5.get_clapTrap());
	std::cout << c2 << std::endl;
	return (0);
}
