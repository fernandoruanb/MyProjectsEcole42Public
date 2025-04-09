/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:30:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/09 15:28:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->number = other.number;
}

Fixed &Fixed::operator=(const Fixed &another)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &another)
	{
		this->number = another.number;
	}
	another.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	int	power;

	power = std::pow(2, bits);
	std::cout << "getRawBits member function called" << std::endl;
	return (number % power);
}

void	Fixed::setRawBits(int const raw)
{
	int	num;

	num = raw << bits;
	this->number = num;
}
