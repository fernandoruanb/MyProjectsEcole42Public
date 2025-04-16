/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:56:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 14:11:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal* c1 = new Cat("gold cat");
	Animal* c2 = new Cat;
	Animal* d1 = new Dog("gold dog");
	Animal* d2 = new Dog;
	WrongAnimal* e1 = new WrongCat("false cat");
	WrongAnimal* e2 = new WrongCat;

	std::cout << std::endl;
	c1->makeSound();
	c2->makeSound();
	d1->makeSound();
	d2->makeSound();
	e1->makeSound();
	e2->makeSound();
	std::cout << std::endl;
//	c1->brain.add_new_idea();
//	d1->brain.add_new_idea();
	std::cout << std::endl;
	delete(c1);
	delete(c2);
	delete(d1);
	delete(d2);
	delete(e1);
	delete(e2);
	return (0);
}
