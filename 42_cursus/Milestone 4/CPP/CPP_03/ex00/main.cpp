/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:11:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/13 11:46:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap MyLittleClapTrap("Bob");
	ClapTrap MySecondLittleClapTrap("WALL-E");

	MyLittleClapTrap.attack("WALL-E");
	MySecondLittleClapTrap.takeDamage(5);
	MySecondLittleClapTrap.beRepaired(2);
	MySecondLittleClapTrap.attack("Bob");
	MyLittleClapTrap.takeDamage(2);
	MyLittleClapTrap.beRepaired(2);
	return (0);
}
