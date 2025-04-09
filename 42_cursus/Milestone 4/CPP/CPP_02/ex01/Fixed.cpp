/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:31:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/09 19:05:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	this->number = n << bits;
}

Fixed::Fixed(const float num)
{
	this->number = num roundf(1 << bits);
}

int	Fixed::toInt(void) const
{
	return (number >> bits);
}

float	Fixed::toFloat(void) const
{
	return (number << bits);
}

Fixed::Fixed(const Fixed &another)
{
	std::cout << "Copy constructor called" << std::endl;
	this.number = another.number;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != other)
	{
		this->number = other.number;
	}
	return (*this);
}
