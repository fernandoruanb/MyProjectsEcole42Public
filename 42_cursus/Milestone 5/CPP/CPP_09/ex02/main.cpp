/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:00:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/04 12:30:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << RED "Error: insufficient arguments" RESET << std::endl;
		return (1);
	}
	long long	index;
	long long	count;
	long long	num;
	bool	flag;
	long long	checker;
	double	startTime;
	double	endTime;
	double	totalTime;
	std::list<int>	pmergeMe;
	std::vector<int> pmergeMe2;
	std::list<int>::const_iterator it;

	index = 0;
	count = 1;
	while (count < argc)
	{
		flag = 0;
		index = 0;
		checker = 0;
		while (argv[count][index] != '\0')
		{
			if (argv[count][index] == ' ')
			{
				++index;
				continue ;
			}	
			if (argv[count][index] >= '0' && argv[count][index] <= '9')
			{
				while (argv[count][index + checker] && argv[count][index + checker] >= '0'
						&& argv[count][index + checker] <= '9')
					checker++;
				if (checker > 1)
					flag = 1;
				std::string	token(argv[count], checker);
				std::stringstream ss(token);
				ss >> num;
				pmergeMe.push_back(num);
				pmergeMe2.push_back(num);
			}
			else
			{
				std::cerr << RED "Error" RESET << std::endl;
				return (1);
			}
			if (flag == 1)
				index += checker;
			else
				++index;
		}
		count++;
	}
	std::cout << MAGENTA "Before: " RESET;
	it = pmergeMe.begin();
	while (it != pmergeMe.end())
	{
		std::cout << BRIGHT_YELLOW << *it << " " << RESET;
		++it;
	}
	std::cout << std::endl;
	startTime = std::clock();
	fordJohnsonList(pmergeMe);
	endTime = std::clock();
	totalTime = (endTime - startTime) / 1000000;
	startTime = std::clock();
	fordJohnsonVector(pmergeMe2);
	endTime = std::clock();
	it = pmergeMe.begin();
	std::cout << MAGENTA "After: " RESET;
	it = pmergeMe.begin();
        while (it != pmergeMe.end())
        {
                std::cout << BRIGHT_YELLOW << *it << " " << RESET;
                ++it;
        }
        std::cout << std::endl;
	std::cout << GREEN "Time to process a range of " << YELLOW << pmergeMe.size() << GREEN " elements with std::list " << ORANGE << std::fixed << std::setprecision(8) << totalTime << GREEN " us" << RESET << std::endl;
	totalTime = (endTime - startTime) / 1000000;
	std::cout << GREEN "Time to process a range of " << YELLOW << pmergeMe2.size() << GREEN " elements with std::vector " << ORANGE << totalTime << GREEN " us" << RESET << std::endl;
	return (0);
}
