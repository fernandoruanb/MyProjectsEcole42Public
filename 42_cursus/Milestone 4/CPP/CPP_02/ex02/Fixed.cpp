/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:35:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/11 09:59:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed	Fixed::operator/(const Fixed &second) const
{
	if (second.toInt() == 0)
	{
		std::cout << "Division by Zero Error" << std::endl;
		return (0);
	}
	return (this->toFloat() / second.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed	result(*this);

	++(*this);
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	number++;
	return (*this);
}

bool	Fixed::operator==(const Fixed &second) const
{
	return (this->toFloat() == second.toFloat());
}

bool	Fixed::operator!=(const Fixed &second) const
{
	return (this->toFloat() != second.toFloat());
}

bool	Fixed::operator<=(const Fixed &second) const
{
	return (this->toFloat() <= second.toFloat());
}

bool	Fixed::operator>=(const Fixed &second) const
{
	return (this->toFloat() >= second.toFloat());
}

bool	Fixed::operator<(const Fixed &second) const
{
	return (this->toFloat() < second.toFloat());
}

bool	Fixed::operator>(const Fixed &second) const
{
	return (this->number > second.number);
}

Fixed	Fixed::operator*(const Fixed &second) const
{
	return (this->toFloat() * second.toFloat());
}

Fixed	Fixed::operator-(const Fixed &second) const
{
	return (this->toFloat() - second.toFloat());
}

Fixed	Fixed::operator+(const Fixed &second) const
{
	return (this->toFloat() + second.toFloat());
}

float	Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() > second.toFloat())
		return (first.toFloat());
	else
		return (second.toFloat());
}

float	Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() < second.toFloat())
		return (first.toFloat());
	else
		return (second.toFloat());
}

float	Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() > second.toFloat())
		return (first.toFloat());
	else
		return (second.toFloat());
}

float	Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() < second.toFloat())
		return (first.toFloat());
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

std::ostream& operator<<(std::ostream& out, const Fixed& myInstance)
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
