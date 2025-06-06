/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:24:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/05 19:12:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"

void	fordJohnsonVector(std::vector<int> &pmergeMe2)
{
	std::vector<int>	highValues;
	std::vector<int>	lowValues;
	std::vector<int>::iterator it;
	std::vector<int>::iterator temp;
	long long	limit;
	long long	count;

	it = pmergeMe2.begin();
	limit = pmergeMe2.size();
	count = 0;
	while (it != pmergeMe2.end())
	{
		temp = it;
                ++it;
                ++count;
                if (count >= limit)
                {
                        if (temp != pmergeMe2.end())
                                lowValues.push_back(*temp);
                        else
                                lowValues.push_back(*it);
                        break ;
                }
                if (*temp > *it)
                {
                        highValues.push_back(*temp);
                        lowValues.push_back(*it);
                }
                else
                {
                        highValues.push_back(*it);
                        lowValues.push_back(*temp);
                }
                ++it;
                ++count;
	}
	std::vector<int>::iterator check = highValues.begin();
	std::vector<int>::iterator start = highValues.begin();
	std::vector<int>::iterator end = highValues.end();
	std::vector<int>::iterator startHigh = highValues.begin();
	std::vector<int>::iterator endHigh = highValues.end();
	std::vector<int>::iterator endLow = lowValues.end();
	std::vector<int>::iterator startLow = lowValues.begin();

	std::sort(start, end);
	start = lowValues.begin();
	end = lowValues.end();
	std::sort(start, end);
	check = pmergeMe2.begin();
	while (check != pmergeMe2.end())
		check = pmergeMe2.erase(check);
	check = pmergeMe2.begin();
	pmergeMe2.resize(highValues.size() + lowValues.size());
	std::merge(startHigh, endHigh, startLow, endLow, check);
}

void	sortList(std::list<int> &highValues, std::list<int> &lowValues, std::list<int> &pmergeME)
{
	std::list<int>::iterator it = pmergeME.begin();
	(void)highValues;
	(void)lowValues;
	std::vector<unsigned int> jacobsthal;
	std::vector<unsigned int> base;
	unsigned int   mark;
	unsigned int   index;
	unsigned int   power;

	mark = 2;
	index = 1;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (index < mark)
	{
		power = jacobsthal[index] + 2 * jacobsthal[index - 1];
		jacobsthal.push_back(power);
		if (power >= lowValues.size())
			break ;
		++mark;
		++index;
        }
	std::vector<unsigned int>::iterator v = jacobsthal.begin();
	std::advance(v, 2);

	// Bulding the base of Jacobsthal

	std::set<unsigned int> sets;
	index = 0;
	while (index < lowValues.size())
	{
		sets.insert(index);
		index++;
	}
	index = 0;
	while (v != jacobsthal.end())
	{
		if (*v <= lowValues.size())
		{
			base.push_back(*v);
			sets.erase(*v);
			index++;
		}
		else
			break ;
		++v;
	}

	// base impression;

	std::cout << WHITE "Base impreesion" RESET << std::endl;
	v = base.begin();
	std::set<unsigned int>::iterator y = sets.begin();
	while (y != sets.end())
	{
		base.push_back(*y);
		++y;
	}
	std::vector<unsigned int>::iterator A;
	while (v != base.end())
	{
		A = v;
		++A;
		if (A == base.end())
			std::cout << *v << "." << std::endl;
		else
			std::cout << *v << ", ";
		++v;
	}
	// If you want to see the Jacobsthal sequence you can see here
	std::vector<unsigned int>::iterator i = jacobsthal.begin();
        std::vector<unsigned int>::iterator f;

	std::cout << WHITE "SEQUENCE OF JACOBSTHAL USED" RESET << std::endl;
	std::cout << std::endl;
        while (i != jacobsthal.end())
        {
                f = i;
                ++f;
                if (f != jacobsthal.end())
                        std::cout << YELLOW << *i << MAGENTA ", " RESET;
                else
                        std::cout << YELLOW << *i << MAGENTA "." RESET << std::endl;
                ++i;
        }
	std::cout << std::endl;
	while (it != pmergeME.end())
		it = pmergeME.erase(it);
	it = highValues.begin();
	while (it != highValues.end())
	{
		pmergeME.push_back(*it);
		++it;
	}
	pmergeME.merge(lowValues);
}

void	fordJohnsonList(std::list<int> &pmergeMe)
{
	std::list<int>	highValues;
	std::list<int>	lowValues;
	std::list<int>::iterator it = pmergeMe.begin();
	std::list<int>::iterator temp;
	long long	limit;
	long long	count;

	limit = pmergeMe.size();
	count = 0;
	while (it != pmergeMe.end())
	{
		temp = it;
		++it;
		++count;
		if (count >= limit)
		{
			if (temp != pmergeMe.end())
				lowValues.push_back(*temp);
			else
				lowValues.push_back(*it);
			break ;
		}
		if (*temp > *it)
		{
			highValues.push_back(*temp);
			lowValues.push_back(*it);
		}
		else
		{
			highValues.push_back(*it);
			lowValues.push_back(*temp);
		}
		++it;
		++count;
	}
	highValues.sort();
	//lowValues.sort();
	sortList(highValues, lowValues, pmergeMe);
}
