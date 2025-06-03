/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeME.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:24:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/03 18:46:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"

void	fordJohnsonVector(std::vector<int> &pmergeMe2)
{
	(void)pmergeMe2;
	std::vector<int>	highValues;
	std::vector<int>	lowValues;
	std::vector<int>::iterator it = pmergeMe2.begin();
	std::vector<int>::iterator temp;
	long long	limit;
	long long	count;

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
	std::vector<int>::const_iterator check = highValues.begin();
	std::vector<int>::iterator start = highValues.begin();
	std::vector<int>::iterator end = highValues.end();
	std::sort(start, end);
        std::cout << WHITE "VECTOR highValues Sorted" RESET << std::endl;
        while (check != highValues.end())
        {
                std::cout << *check << std::endl;
                ++check;
        }
        check = lowValues.begin();
        std::cout << WHITE "VECTOR lowValues" RESET << std::endl;
        while (check != lowValues.end())
        {
                std::cout << *check << std::endl;
                ++check;
        }
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
	std::list<int>::const_iterator check = highValues.begin();
	highValues.sort();
	std::cout << WHITE "LIST highValues Sorted" RESET << std::endl;
	while (check != highValues.end())
	{
		std::cout << *check << std::endl;
		++check;
	}
	check = lowValues.begin();
	std::cout << WHITE "LIST lowValues" RESET << std::endl;
	while (check != lowValues.end())
	{
		std::cout << *check << std::endl;
		++check;
	}
}
