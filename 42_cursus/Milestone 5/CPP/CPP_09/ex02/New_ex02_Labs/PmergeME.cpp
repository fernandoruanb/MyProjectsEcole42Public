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

void	sortHighVector(std::vector<unsigned int> &vectorHigh)
{
	std::vector<unsigned int>::iterator s = vectorHigh.begin();
	std::vector<unsigned int>::iterator e = vectorHigh.end();

	std::sort(s, e);
}

void	generateVectorJacobsthal(std::vector<unsigned int> &jacobVector, size_t limit)
{
	jacobVector.clear();

	long long	number;
	std::vector<unsigned int>::iterator it = jacobVector.begin();
	std::vector<unsigned int>::iterator next;

	jacobVector.push_back(0);
	jacobVector.push_back(1);
	while (1)
	{
		next = it;
		++next;
		number = *next + 2 * *it;
		if (number > limit)
			break ;
		jacobVector.push_back(number);
	}
}

void	generateListJacobsthal(std::list<unsigned int> &jacobList, size_t limit)
{
	jacobList.clear();

	long long	number;
	std::list<unsigned int>::iterator it = jacobList.begin();
	std::list<unsigned int>::iterator next;

	jacobList.push_back(0);
	jacobList.push_back(1);
	while (1)
	{
		next = it;
		++next;
		number = *next + 2 * *it;
		if (number > limit)
			break ;
		jacobList.push_back(number);
		++it;
	}
}

void	sortHighList(std::list<unsigned int> &listHigh)
{
	listHigh.sort();
}
