/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:59:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/25 09:55:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int N): capacity(N)
{
	std::cout << BRIGHT_GREEN << "Default constructor called" RESET << std::endl;
}

Span::~Span(void)
{
	std::cout << RED << "Destructor called" RESET << std::endl;
}

int	Span::longestSpan(void) const
{
	int	min;
	int	max;

	if (number.size() < 2)
		throw std::exception();
	min = *std::min_element(number.begin(), number.end());
	max = *std::max_element(number.begin(), number.end());
	std::cout << GREEN "min: " RESET << YELLOW << min << RESET << std::endl;
	std::cout << GREEN "max: " RESET << YELLOW << max << RESET << std::endl;
	return (max - min);
}

int	Span::shortestSpan(void) const
{
	int	minDiff;
	int	temp;
	unsigned int	index;
	std::vector<int> sorted;

	if (number.size() < 2)
		throw std::exception();
	sorted = getNumber();
	std::sort(sorted.begin(), sorted.end());
	index = 1;
	minDiff = sorted[index] - sorted[index - 1];
	while (index < sorted.size())
	{
		temp = sorted[index] - sorted[index - 1];
		if (temp < minDiff)
			minDiff = temp;
		index++;
	}
	return (minDiff);
}

Span&	Span::operator=(const Span &other)
{
	std::cout << YELLOW "Copy assignment operator called" RESET << std::endl;
	if (this != &other)
	{
		this->number = other.getNumber();
		this->capacity = other.getCapacity();
	}
	return (*this);
}

Span::Span(const Span &other): number(other.getNumber()), capacity(other.getCapacity())
{
	std::cout << GREEN "Copy constructor called" RESET << std::endl;
}

const std::vector<int>&	Span::getNumber(void) const
{
	return (number);
}

unsigned int	Span::getCapacity(void) const
{
	return (capacity);
}

unsigned int	Span::getSize(void) const
{
	return (number.size());
}

void	Span::addNumber(int number)
{
	if (this->getSize() < this->getCapacity())
	{
		this->number.push_back(number);
		std::cout << ORANGE << "Number " << YELLOW << number << RESET << ORANGE " added successfully!!!" RESET << std::endl;
	}
	else
		throw std::exception();
}
