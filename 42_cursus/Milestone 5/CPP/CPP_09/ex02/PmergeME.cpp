/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:24:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/04 12:21:30 by fruan-ba         ###   ########.fr       */
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
	lowValues.sort();
	sortList(highValues, lowValues, pmergeMe);
}
