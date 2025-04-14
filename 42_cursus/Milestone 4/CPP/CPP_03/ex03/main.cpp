/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:24:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/14 16:10:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	FragTrap c1("Attacker");
	ScavTrap a1("Defender 1");
	ScavTrap a2("Defender 2");
	ClapTrap b1("attacker");
	DiamondTrap d1("Diamond Warrior");

	a1.guardGate();
	a2.guardGate();
	c1.attack(a1.get_claptrap_name());
	c1.attack(a2.get_claptrap_name());
	a1.takeDamage(70);
	a2.takeDamage(20);
	b1.attack(a1.get_claptrap_name());
	a1.takeDamage(30);
	a2.attack(b1.get_claptrap_name());
	b1.takeDamage(100);
	c1.attack(a2.get_claptrap_name());
	a2.takeDamage(79);
	a2.beRepaired(80);
	c1.attack(a2.get_claptrap_name());
	a2.takeDamage(79);
	c1.highFivesGuys();
	d1.attack(c1.get_claptrap_name());
	c1.takeDamage(100);
	d1.whoAmI();
	return (0);
}
