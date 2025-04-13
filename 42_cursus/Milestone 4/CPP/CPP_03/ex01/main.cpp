/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:18:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/13 14:23:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serena.hpp"

int	main(void)
{
	ScavTrap MyLittleRobot("Bob");
	ScavTrap MySecondLittleRobot("James");

	MyLittleRobot.attack("James");
	MySecondLittleRobot.takeDamage(2);
	MySecondLittleRobot.attack("Bob");
	MyLittleRobot.takeDamage(3);
	MyLittleRobot.beRepaired(2);
	return (0);
}
