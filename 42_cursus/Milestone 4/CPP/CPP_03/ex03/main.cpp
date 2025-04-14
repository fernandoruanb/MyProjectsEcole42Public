/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 22:06:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/14 10:32:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap MyLittleDiamondTrap("Bobobi");
	DiamondTrap MySecondLittleDiamondTrap("Optimus Prime");

	MyLittleDiamondTrap.attack("Optimus Prime");
	MySecondLittleDiamondTrap.attack("Bobobi");
	MyLittleDiamondTrap.attack("Optimus Prime");
        MySecondLittleDiamondTrap.attack("Bobobi");
	MyLittleDiamondTrap.attack("Optimus Prime");
        MySecondLittleDiamondTrap.attack("Bobobi");
	MyLittleDiamondTrap.attack("Optimus Prime");
        MySecondLittleDiamondTrap.attack("Bobobi");
	MyLittleDiamondTrap.attack("Optimus Prime");
        MySecondLittleDiamondTrap.attack("Bobobi");
	MyLittleDiamondTrap.attack("Optimus Prime");
        MySecondLittleDiamondTrap.attack("Bobobi");
	MyLittleDiamondTrap.attack("Optimus Prime");
        MySecondLittleDiamondTrap.attack("Bobobi");
	MyLittleDiamondTrap.takeDamage(15);
	MySecondLittleDiamondTrap.takeDamage(15);
	MyLittleDiamondTrap.takeDamage(15);
        MySecondLittleDiamondTrap.takeDamage(15);
	MyLittleDiamondTrap.takeDamage(15);
        MySecondLittleDiamondTrap.takeDamage(15);
	MyLittleDiamondTrap.takeDamage(15);
        MySecondLittleDiamondTrap.takeDamage(15);
	MyLittleDiamondTrap.takeDamage(15);
        MySecondLittleDiamondTrap.takeDamage(15);
	MySecondLittleDiamondTrap.takeDamage(100);
	MySecondLittleDiamondTrap.guardGate();
	MySecondLittleDiamondTrap.highFivesGuys();
	return (0);
}
