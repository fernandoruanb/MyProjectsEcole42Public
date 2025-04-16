/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:07:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 13:35:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : type("aleatory_dog")
{
	std::cout << "Dog empty constructor called for aleatory_dog Dog" << std::endl;
	brain = new Brain alpha;
}

Dog::Dog(std::string type) : type(type)
{
	std::cout << "Dog default input constructor called for " << type << " Dog" << std::endl;
	brain = new Brain alpha;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called for " << type << " Dog" << std::endl;
	delete(this->brain);
}

Dog::Dog(const Dog &other)
{
	std::cout << "Copy constructor called for " << type << " Dog" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment called for " << type << " Dog" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

std::string Dog::get_dog_type(void) const
{
	return (type);
}

std::ostream& operator<<(std::ostream &out, const Dog &other)
{
	out << other.get_dog_type() << std::endl;
	return (out);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Wooooof" << std::endl;
}
