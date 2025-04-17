/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:13:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/17 09:39:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : type("aleatory_wrong_cat")
{
	std::cout << "WrongCat empty default constructor WrongCat called for aleatory_wrong_cat" << std::endl;
	brain = new Brain;
}

WrongCat::WrongCat(std::string type) : type(type)
{
	std::cout << "WrongCat default input constructor called for " << type << " WrongCat" << std::endl;
	brain = new Brain;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called for " << type << " WrongCat" << std::endl;
	delete(this->brain);
}

WrongCat::WrongCat(const WrongCat &other)
{
	std::cout << "WrongCat copy constructor called for " << type << " WrongCat" << std::endl;
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignment for " << type << " WrongCat" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: Wooooooooooooooooooof" << std::endl;
}

std::string WrongCat::getType(void) const
{
	return (type);
}

std::ostream& operator<<(std::ostream &out, const WrongCat &other)
{
	out << other.getType() << std::endl;
	return (out);
}
