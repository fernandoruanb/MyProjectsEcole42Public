/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:20:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/07 14:20:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"

static void	showVector(std::vector<unsigned int> v)
{
	std::vector<unsigned int>::iterator c = v.begin();
	std::vector<unsigned int>::iterator next;

	std::cout << WHITE "VECTOR" RESET << std::endl;
	while (c != v.end())
	{
		next = c;
		++next;
		if (next == v.end())
			std::cout << YELLOW << *c << ORANGE "." RESET << std::endl;
		else
			std::cout << YELLOW << *c << ORANGE ", " RESET;
		++c;
	}
}

static void	showList(std::list<unsigned int> l)
{
	std::list<unsigned int>::iterator c = l.begin();
	std::list<unsigned int>::iterator next;

	std::cout << WHITE "LIST" RESET << std::endl;
	while (c != l.end())
	{
		next = c;
		++next;
		if (next == l.end())
			std::cout << YELLOW << *c << ORANGE "." RESET << std::endl;
		else
			std::cout << YELLOW << *c << ORANGE ", " RESET;
		++c;
	}
}

void	sortHighVector(std::vector<unsigned int> &vectorHigh)
{
	std::vector<unsigned int>::iterator s = vectorHigh.begin();
	std::vector<unsigned int>::iterator e = vectorHigh.end();

	std::sort(s, e);
}

void	generateVectorJacobsthal(std::vector<unsigned int> &jacobVector, std::vector<unsigned int> &orderVector, size_t limit)
{
	jacobVector.clear();

	size_t	number;
	size_t	index;
	std::vector<unsigned int>::iterator it = jacobVector.begin();
	std::set<unsigned int> indexes;
	std::vector<unsigned int>::iterator next;
	size_t	value;

	// Full indexes

	index = 2;
	while (index < limit)
	{
		indexes.insert(index);
		++index;
	}

	jacobVector.push_back(0);
	jacobVector.push_back(1);
	index = 1;
	while (1)
	{
		number = jacobVector[index] + 2 * jacobVector[index - 1];
		if (number > limit)
			break ;
		jacobVector.push_back(number);
		indexes.erase(number);
		++it;
		++index;
	}
	it = jacobVector.begin();
	while (it != jacobVector.end())
	{
		orderVector.push_back(*it);
		++it;
	}
	showVector(jacobVector);
	std::set<unsigned int>::iterator s = indexes.begin();
	while (s != indexes.end())
	{
		value = *s;
		it = std::lower_bound(orderVector.begin(), orderVector.end(), value);
		orderVector.insert(it, value);
		++s;
	}
	showVector(orderVector);
}

void	generateListJacobsthal(std::list<unsigned int> &jacobList, std::list<unsigned int> &orderList, size_t limit)
{
	jacobList.clear();

	size_t	number;
	size_t	index;
	size_t	value;
	std::set<unsigned int> indexes;
	std::list<unsigned int>::iterator it = jacobList.begin();
	std::list<unsigned int>::iterator next;

	// full indexes
	index = 2;
	while (index < limit)
	{
		indexes.insert(index);
		++index;
	}
	jacobList.push_back(0);
	jacobList.push_back(1);
	++it;
	while (it != jacobList.end())
	{
		next = it;
		++next;
		if (next == jacobList.end())
			break ;
		number = *next + 2 * *it;
		if (number > limit)
			break ;
		jacobList.push_back(number);
		indexes.erase(number);
		++it;
	}
	showList(jacobList);

	// Insertion order

	it = jacobList.begin();
	while (it != jacobList.end())
	{
		orderList.push_back(*it);
		++it;
	}

	std::set<unsigned int>::iterator s = indexes.begin();
	while (s != indexes.end())
	{
		it = orderList.begin();
		value = *s;
		while (it != orderList.end() && value > *it)
			++it;
		orderList.insert(it, value);
		++s;
	}
	showList(orderList);
}

void	sortHighList(std::list<unsigned int> &listHigh)
{
	listHigh.sort();
}
