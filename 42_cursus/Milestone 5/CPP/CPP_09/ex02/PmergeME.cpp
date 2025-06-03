/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:24:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/03 12:29:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"

/*static void	fillList(std::list<int> &highValues, std::list<int> &lowValues, std::list<int> &pmergeMe)
{

}*/

static void	sortLow(std::list<int> &lowValues)
{
	std::list<int>::iterator it = lowValues.begin();
        std::list<int>::iterator magic;

        while (it != lowValues.end())
        {
                magic = it;
                ++magic;
                if (magic == lowValues.end())
                        break ;
                if(*magic < *it)
                {
                        std::swap(*magic, *it);
                        it = lowValues.begin();
                }
                ++it;
        }
}

static void	sortHigh(std::list<int> &highValues)
{
	std::list<int>::iterator it = highValues.begin();
        std::list<int>::iterator magic;

        while (it != highValues.end())
        {
                magic = it;
                ++magic;
                if (magic == highValues.end())
                        break ;
                if(*magic < *it)
                {
                        std::swap(*magic, *it);
                        it = highValues.begin();
                }
                ++it;
        }
}

static void	sortList(std::list<int> &highValues, std::list<int> &lowValues)
{
	sortHigh(highValues);
	sortLow(lowValues);
}

void	fordJohnsonVector(std::vector<int> &pmergeMe2)
{
	(void)pmergeMe2;
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
	sortList(highValues, lowValues);
	std::list<int>::const_iterator check = highValues.begin();
	std::cout << WHITE "highValues" RESET << std::endl;
	while (check != highValues.end())
	{
		std::cout << *check << std::endl;
		++check;
	}
	check = lowValues.begin();
	std::cout << WHITE "lowValues" RESET << std::endl;
	while (check != lowValues.end())
	{
		std::cout << *check << std::endl;
		++check;
	}
}
