/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:06:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 20:35:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>
#include <string>

Zombie*	Zombie::zombieHorde(int N, std::string name)
{
	int	index;
	Zombie*	MyZombieHorde;

	if (N <= 0)
		return (NULL);
	MyZombieHorde = new Zombie[N];
	index = 0;
	while (index < N)
	{
		std::ostringstream oss;
		oss << name << "_" << index;
		MyZombieHorde[index].set_name(oss.str());
		MyZombieHorde[index].announce();
		index++;
	}
	return (MyZombieHorde);
}
