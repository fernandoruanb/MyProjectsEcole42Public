/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:35:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 09:50:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : type("aleatory_cat")
{
	std::cout << "Cat Empty default constructor called for aleatory_cat Cat" << std::endl;
}

Cat::Cat(std::string type) : type(type)
{
	std::cout << "Cat input default constructor called for " << type << " Cat" < std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Destructor called for " << type << " Cat" << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Copy constructor called for " << type << " Cat" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator called for " << type << " Cat" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	makeSound(void) const
{
	std::cout << "Meoooowwwww!!!" << std::endl;
}
