/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:59:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/22 15:31:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

class Array;

template<typename A>
Array::Array(void): data(NULL), length(0)
{
	std::cout << GREEN "Default constructor called" RESET << std::endl;
}

template<typename A>
Array::~Array(void)
{
	std::cout << BLUE "Destructor called" RESET << std::endl;
}

template<typename A>
Array::Array(const Array &another): data(another.get_data()), length(another.get_length())
{
	std::cout << BRIGHT_MAGENTA "Copy constructor called" RESET << std::endl;
}

template<typename A>
unsigned int	Array::size(void) const
{
	return (this->length);
}

template<typename A>
unsigned int	Array::get_length(void) const
{
	return (this->length);
}

template<typename A>
A const*	Array::get_data(void) const
{
	return (this->data);
}

template<typename A>
A*	Array::get_data(void)
{
	return (this->data);
}

template<typename A>
Array&	Array::operator=(const &Array another)
{
	std::cout << BRIGHT_YELLOW "Copy assignment operator called" RESET << std::endl;
	this->length = another.get_length();
	this->data = another.get_data();
	return (*this);
}

A&	Array::operator[](unsigned int index) 
{
	if (index >= this->length)
		throw std::runtime_error("Operator[] Index Error");
	return (this->data[index]);
}

A const&	Array::operator[](unsigned int index) const 
{
	if (index >= this->length)
		throw std::runtime_error( RED "Operator[] Index Error" RESET);
	return (this->data[index]);
}

std::ostream& operator<<(std::ostream &out, const Array<OUT> &another)
{
	out << BRIGT_BLUE "That's ok" RESET << std::endl;
	return (out);
}
