/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:35:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/10 11:46:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

int	Fixed::operator/(const Fixed &second) const
{
	if (second.number == 0)
	{
		std::cout << "Division by Zero Error" << std::endl;
		return (0);
	}
	return (this->number / second.number);
}

void	Fixed::operator++(int num)
{
	number += num;
}

void	Fixed::operator++(void)
{
	number += 1;
}

bool	Fixed::operator==(const Fixed &second) const
{
	return (this->number == second.number);
}

bool	Fixed::operator!=(const Fixed &second) const
{
	return (this->number != second.number);
}

bool	Fixed::operator<=(const Fixed &second) const
{
	return (this->number <= second.number);
}

bool	Fixed::operator>=(const Fixed &second) const
{
	return (this->number >= second.number);
}

bool	Fixed::operator<(const Fixed &second) const
{
	return (this->number < second.number);
}

bool	Fixed::operator>(const Fixed &second) const
{
	return (this->number > second.number);
}

int	Fixed::operator*(const Fixed &second) const
{
	return (this->number * second.number);
}

int	Fixed::operator-(const Fixed &second) const
{
	return (this->number - second.number);
}

int	Fixed::operator+(const Fixed &second) const
{
	return (this->number + second.number);
}

int	Fixed::max(const Fixed &second) const
{
	if (this->number > second.number)
		return (this->number.toFloat());
	else
		return (second.toFloat());
}

int	Fixed::min(const Fixed &second) const
{
	if (this->number < second.number)
		return (this->number.toFloat());
	else
		return (second.toFloat());
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	number = n << bits;
}

std::ostream Fixed::operator<<(std::ostream &out, Fixed &myInstance)
{
	out << myInstance.toFloat();
	return (out);
}

int	Fixed::toInt(void) const
{
	return (number >> bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)number / roundf(1 << bits));
}

Fixed::Fixed(const Fixed &another)
{
	std::cout << "Copy constructor called" << std::endl;
	this->number = another.number;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->number = other.number;
	}
	return (*this);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	number = roundf(num * (1 << bits));
}
