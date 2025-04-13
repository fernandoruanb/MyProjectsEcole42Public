/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:24:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/13 19:43:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap First("James");
	FragTrap Second("Optimus");

	First.attack("Optimus");
	Second.attack("James");
	First.attack("Optimus");
        Second.attack("James");
	First.attack("Optimus");
        Second.attack("James");
	First.attack("Optimus");
        Second.attack("James");
	First.attack("Optimus");
        Second.attack("James");
	First.attack("Optimus");
        Second.attack("James");
	First.takeDamage(10);
	Second.takeDamage(10);
	First.takeDamage(10);
        Second.takeDamage(10);
	First.takeDamage(10);
        Second.takeDamage(10);
	First.takeDamage(10);
        Second.takeDamage(10);
	First.takeDamage(10);
        Second.takeDamage(10);
	First.highFivesGuys();
	Second.highFivesGuys();
	return (0);
}
