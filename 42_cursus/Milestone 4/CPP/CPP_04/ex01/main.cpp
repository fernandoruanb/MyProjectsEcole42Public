/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:56:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 16:01:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	int	index;
	Animal* animals[100];

	index = 0;
	while (index < 50)
	{
		animals[index] = new Dog;
		index++;
	}
	while (index < 100)
	{
		animals[index] = new Cat;
		index++;
	}
	index = 0;
	while (index < 100)
	{
		delete(animals[index]);
		index++;
	}
	return (0);
}
