/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:30:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 20:30:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	name;
	Zombie*	MyZombie;

	std::cout << std::endl;
	std::cout << "🧙: What is the name of the persistent zombie: ";
	std::getline(std::cin, name);
	if (name.empty())
	{
		std::cout << std::endl;
		std::cout << "🧙: You need to choose a name, man! D=" << std::endl;
		return (1);
	}
	MyZombie = Zombie::newZombie(name);
	MyZombie->announce();
	delete(MyZombie);
	std::cout << std::endl << std::endl;
	std::cout << "🧙: Now, I need to know about the second name for the temporary zombie: ";
	std::getline(std::cin, name);
	if (name.empty())
	{
		std::cout << std::endl;
		std::cout << "🧙: Oh, man, you can't forget the name of your zombie!" << std::endl;
		return (1);
	}
	Zombie::randomChump(name);
	std::cout << std::endl;
	return (0);
}
