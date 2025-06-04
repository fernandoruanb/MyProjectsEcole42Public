/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:00:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/04 15:19:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"

static bool	checkVectorSort(std::vector<int> pmergeMe2)
{
	std::vector<int>::iterator it = pmergeMe2.begin();
	std::vector<int>::iterator next;

	while (it != pmergeMe2.end())
	{
		next = it;
		++next;
		if (next == pmergeMe2.end())
			return (1);
		if (*it > *next)
			return (0);
		++it;
	}
	return (1);
}

static bool	checkListSort(std::list<int> pmergeMe)
{
	std::list<int>::iterator it = pmergeMe.begin();
	std::list<int>::iterator next;

	while (it != pmergeMe.end())
	{
		next = it;
		++next;
		if (next == pmergeMe.end())
			return (1);
		if (*it > *next)
			return (0);
		++it;
	}
	return (1);
}

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
	std::list<int>::iterator it;

	index = 0;
	count = 1;
	while (count < argc)
	{
		flag = 0;
		index = 0;
		checker = 0;
		while (argv[count][index] != '\0')
		{
			while (argv[count][index] && argv[count][index] == ' ')
				++index;
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
				if (num < 0 || num > INT_MAX)
				{
					std::cerr << RED "Error: overflow/underflow detected" RESET << std::endl;
					return (1);
				}
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
	if (pmergeMe.size() == 0 || pmergeMe2.size() == 0)
	{
		std::cerr << RED "Error: empty values" RESET << std::endl;
		return (1);
	}
	std::cout << MAGENTA "Before LIST: " RESET;

	// I am showing to you all values into LIST here
	it = pmergeMe.begin();
	while (it != pmergeMe.end())
	{
		std::cout << BRIGHT_YELLOW << *it << " " << RESET;
		++it;
	}
	// I am showing to you all values into VECTOR here
	std::vector<int>::iterator itv = pmergeMe2.begin();
	std::cout << std::endl << std::endl;
	std::cout << MAGENTA "Before VECTOR: " RESET;
	while (itv != pmergeMe2.end())
	{
		std::cout <<  BRIGHT_YELLOW << *itv << " " << RESET;
		++itv;
	}

	// Start Ford-Johnson algorithm and calculate clocks
	std::cout << std::endl << std::endl;
	startTime = std::clock();
	fordJohnsonList(pmergeMe);
	endTime = std::clock();
	totalTime = (endTime - startTime) / 1000000;
	startTime = std::clock();
	fordJohnsonVector(pmergeMe2);
	endTime = std::clock();
	it = pmergeMe.begin();
	std::cout << MAGENTA "After LIST: " RESET;

	// I am here showing the result of LIST
	it = pmergeMe.begin();
        while (it != pmergeMe.end())
        {
                std::cout << BRIGHT_YELLOW << *it << " " << RESET;
                ++it;
        }
	std::cout << std::endl << std::endl;
	// I am here showing the result of VECTOR
	std::cout << MAGENTA "After VECTOR: " RESET;
	itv = pmergeMe2.begin();
	while (itv != pmergeMe2.end())
	{
		std::cout << BRIGHT_YELLOW << *itv << " " << RESET;
		++itv;
	}
        std::cout << std::endl << std::endl;

	// Check the work!!!
	if (checkListSort(pmergeMe))
		std::cout << BRIGHT_GREEN "LIST is Sorted =D!!!" RESET << std::endl;
	else
		std::cerr << RED "LIST ISN'T SORTED D=" RESET << std::endl;
	if (checkVectorSort(pmergeMe2))
		std::cout << BRIGHT_GREEN "VECTOR is Sorted =D!!!" RESET << std::endl;
	else
		std::cerr << RED "VECTOR INS'T SORTED D=" RESET << std::endl;

	// Now, I will show the time of each process here
	std::cout << WHITE "Time to process a range of " << YELLOW << pmergeMe.size() << WHITE " elements with " << GREEN "std::list " << ORANGE << std::fixed << std::setprecision(8) << totalTime << WHITE " us" << RESET << std::endl;
	totalTime = (endTime - startTime) / 1000000;
	std::cout << WHITE "Time to process a range of " << YELLOW << pmergeMe2.size() << WHITE " elements with " << GREEN "std::vector " << ORANGE << totalTime << WHITE " us" << RESET << std::endl;
	return (0);
}
