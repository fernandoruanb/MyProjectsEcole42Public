/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:56:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 16:50:19 by fruan-ba         ###   ########.fr       */
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
	Dog *dog = dynamic_cast<Dog*>(animals[0]);
	if (dog)
		dog->get_brain().add_new_idea();
	Cat *cat = dynamic_cast<Cat*>(animals[50]);
	if (cat)
		cat->get_cat_brain().add_new_idea();
	std::cout << std::endl << std::endl;
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl << std::endl;
	index = 0;
	while (index < 100)
	{
		delete(animals[index]);
		index++;
	}
	return (0);
}
