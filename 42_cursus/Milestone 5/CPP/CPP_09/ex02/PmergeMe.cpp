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

#include "PmergeMe.hpp"

bool	isListSorted(std::list<unsigned int> l)
{
	std::list<unsigned int>::iterator itl = l.begin();
	std::list<unsigned int>::iterator nl;

	while (itl != l.end())
	{
		nl = itl;
		++nl;
		if (nl == l.end())
			break ;
		else if (*nl >= *itl)
			++itl;
		else
		{
			std::cerr << RED "LIST isn't sorted D=" RESET << std::endl;
			return (0);
		}
	}
	std::cout << BRIGHT_GREEN "LIST is sorted =D" RESET << std::endl;
	return (1);
}

bool	isVectorSorted(std::vector<unsigned int> v)
{
	std::vector<unsigned int>::iterator itv = v.begin();
	std::vector<unsigned int>::iterator nv;

	while (itv != v.end())
	{
		nv = itv;
		++nv;
		if (nv == v.end())
			break ;
		else if (*nv >= *itv)
			++itv;
		else
		{
			std::cerr << RED "VECTOR isn't sorted D=" RESET << std::endl;
			return (0);
		}
	}
	std::cout << BRIGHT_GREEN "VECTOR is sorted =D" RESET << std::endl;
	return (1);
}

void	showVector(std::vector<unsigned int> v)
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

static void	showSet(std::set<unsigned int> s)
{
	std::set<unsigned int>::iterator c = s.begin();
	std::set<unsigned int>::iterator next;

	std::cout << WHITE "SET" RESET << std::endl;
	while (c != s.end())
	{
		next = c;
		++next;
		if (next == s.end())
			std::cout << YELLOW << *c << ORANGE "." RESET << std::endl;
		else
			std::cout << YELLOW << *c << ORANGE ", " RESET;
		++c;
	}
}

void	showList(std::list<unsigned int> l)
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

void	doTheMagicList(std::list<unsigned int> &listHigh, std::list<unsigned int> &listLow, std::list<unsigned int> &orderList)
{
	std::list<unsigned int>::iterator index = orderList.begin();
	std::list<unsigned int>::iterator value;
	std::list<unsigned int>::iterator target;

	while (index != orderList.end())
	{
		value = listLow.begin();
		target = listHigh.begin();
		std::advance(value, *index);
		if (value == listLow.end())
			break ;
		while (target != listHigh.end() && *value > *target)
			++target;
		listHigh.insert(target, *value);
		++index;
	}
}

void	doTheMagicVector(std::vector<unsigned int> &vectorHigh, std::vector<unsigned int> &vectorLow, std::vector<unsigned int> &orderVector)
{
	long long	value;
	std::vector<unsigned int>::iterator index = orderVector.begin();
	std::vector<unsigned int>::iterator target;

	while (index != orderVector.end())
	{
		value = vectorLow[*index];
		target = std::lower_bound(vectorHigh.begin(), vectorHigh.end(), value);
		vectorHigh.insert(target, value);
		++index;
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

	index = 0;
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
		++it;
		++index;
	}
	index = 2;
	while (index < jacobVector.size())
	{
		value = jacobVector[index] - 1;
		indexes.erase(value);
		if (value >= 0)
			orderVector.push_back(jacobVector[index] - 1);
		++index;
	}
	std::set<unsigned int>::iterator s = indexes.begin();
	while (s != indexes.end())
	{
		value = *s;
		orderVector.push_back(value);
		++s;
	}
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
	index = 0;
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
		++it;
	}

	// Insertion order

	it = jacobList.begin();
	std::advance(it, 2);
	while (it != jacobList.end())
	{
		value = *it;
		--value;
		if (value >= 0)
		{
			orderList.push_back(value);
			indexes.erase(value);
		}
		++it;
	}
	std::set<unsigned int>::iterator s = indexes.begin();
	while (s != indexes.end())
	{
		it = orderList.begin();
		value = *s;
		orderList.push_back(value);
		++s;
	}
}

void	sortHighList(std::list<unsigned int> &listHigh)
{
	listHigh.sort();
}
