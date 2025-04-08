/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:24:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 20:57:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int	main(void)
{
	std::string num_of_zombies;
	std::string	name;
	Zombie*	MyZombies;
	int	real_number;

	std::cout << std::endl;
	std::cout << "🧙: How many zombies do you want? ";
	std::getline(std::cin, num_of_zombies);
	if (num_of_zombies.empty())
	{
		std::cout << "🧙: You need to pass something to continue!" << std::endl;
		return (1);
	}
	real_number = std::atoi(num_of_zombies.c_str());
	if (real_number > 10000 || real_number <= 0)
	{
		std::cout << std::endl;
		std::cout << "🧙: Invalid number of zombies, man! D=" << std::endl;
		std::cout << std::endl;
		return (1);
	}
	std::cout << std::endl;
	std::cout << "🧙: Ok, I also need to know what name do you want to give them: ";
	std::getline(std::cin, name);
	if (name.empty())
	{
		std::cout << std::endl;
		std::cout << "🧙: You need to choose a name for your children =D" << std::endl;
		return (1);
	}
	MyZombies = Zombie::zombieHorde(real_number, name);
	std::cout << std::endl << std::endl;
	std::cout << "🧙: Your zombies are made!!!" << std::endl;
	delete[] MyZombies;
	std::cout << std::endl;
	return (0);
}
