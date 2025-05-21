/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:24:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 15:50:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap c1("Attacker");
	ClapTrap a1("Defender 1");
	FragTrap a2("Defender 2");
	ClapTrap b1("attacker");

	std::cout << "Name: " << a2.get_name() << std::endl;
        std::cout << "Hit Points: " << a2.get_hit_points() << std::endl;
        std::cout << "Energy: " << a2.get_energy() << std::endl;
        std::cout << "Attack_Damage: " << a2.get_attack_damage() << std::endl;
	c1.attack(a1.get_clapTrap());
	c1.attack(a2.get_clapTrap());
	a1.takeDamage(70);
	a2.takeDamage(20);
	b1.attack(a1.get_clapTrap());
	a1.takeDamage(30);
	a2.attack(b1.get_clapTrap());
	b1.takeDamage(100);
	c1.attack(a2.get_clapTrap());
	a2.takeDamage(79);
	a2.beRepaired(80);
	c1.attack(a2.get_clapTrap());
	a2.takeDamage(79);
	c1.highFivesGuys();
	return (0);
}
