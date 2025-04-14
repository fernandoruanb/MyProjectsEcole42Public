/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:18:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/14 17:07:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap c1("James");
	ClapTrap c2("Robert");
	ScavTrap a1("Optimus");
	ScavTrap a2("Defender");

	a2.guardGate();
	a1.attack("James");
	c1.takeDamage(20);
	c2.attack(a1.get_clapTrap());
	a1.takeDamage(10);
	a1.attack(c2.get_clapTrap());
	c2.takeDamage(9);
	c2.beRepaired(7);
	c2.attack(a1.get_clapTrap());
	a1.takeDamage(30);
	a1.beRepaired(20);
	c2.attack(a1.get_clapTrap());
	a1.takeDamage(30);
	a1.attack(c2.get_clapTrap());
	c2.takeDamage(100);
	a1.guardGate();
	return (0);
}
