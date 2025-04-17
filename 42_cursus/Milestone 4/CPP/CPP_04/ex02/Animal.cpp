/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:29:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/17 09:40:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("aleatory_animal")
{
	std::cout << "Animal empty constructor called for " << "aleatory_animal" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << "Animal default input constructor called for " << type << " Animal" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called for " << type << " Animal" << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->type = other.type;
}

std::string Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << "A loud, clear sound by an animal" << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Animal &other)
{
	out << other.getType() << std::endl;
	return (out);
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}
