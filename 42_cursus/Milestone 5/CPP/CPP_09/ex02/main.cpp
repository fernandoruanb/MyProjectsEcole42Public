/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:00:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/05 13:31:03 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"

static void	studyTimeListVectors(void);

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

	// Now, we can understand about everything!!! Uncomment the following line below
	std::cout << std::endl;
	studyTimeListVectors();
	return (0);
}

static void	studyTimeListVectors(void)
{
	std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
	std::cout << std::string(27, ' ') << BRIGHT_WHITE "TEST 1" RESET << std::endl;
	std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;

	long long	value;
	double	start;
	double	end;
	std::list<int> testList;
	std::vector<int> testVector;

	value = 0;
	start = std::clock();
	while (value < 1000000)
	{
		testList.push_back(value);
		value++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN << "HOGWARDS" << std::endl;
	std::cout << ORANGE "The time to put 1.000.000 elements on " << GREEN "LIST " << ORANGE "is " << YELLOW  << (end - start) / CLOCKS_PER_SEC << ORANGE " s" << RESET <<  std::endl;
	start = std::clock();
	value = 0;
	while (value < 1000000)
	{
		testVector.push_back(value);
		value++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN << "RESTAURANT" << std::endl;
	std::cout << ORANGE "The time to put 1.000.000 elements on " << GREEN << "VECTOR " << ORANGE "is " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE " s" << RESET << std::endl;

	std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
        std::cout << std::string(27, ' ') << BRIGHT_WHITE "TEST 2" RESET << std::endl;
        std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;

	value = 0;
	testList.clear();
	start = std::clock();
	while (value < 1000000)
	{
		testList.push_front(value);
		value++;
	}
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN << "POINTERS" << std::endl;
	std::cout << ORANGE "The time to put front 1.000.000 elements on " << GREEN << "LIST " << ORANGE "is " << YELLOW << (end - start) / CLOCKS_PER_SEC << ORANGE " s" << RESET << std::endl;
	std::cout << WHITE "KEYWORD: " << GREEN << "CHAOS" << std::endl;
	std::cout << MAGENTA "Vector: " << LIGHT_BLUE "I gave up! " << GREEN "LIST won!" RESET << std::endl;

	std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;
        std::cout << std::string(27, ' ') << BRIGHT_WHITE "TEST 3" RESET << std::endl;
        std::cout << BRIGHT_MAGENTA << std::string(60, '=') << RESET << std::endl;

	std::srand(std::time(NULL));
	value = rand() % 1000000;
	std::list<int>::iterator it = testList.begin();
	start = std::clock();
	while (it != testList.end())
	{
		if (*it == value)
		{
			std::cout << GREEN "Value found: " << YELLOW <<  value << GREEN "!!!" << RESET << std::endl;
			break ;
		}
		++it;
	}
	if (it == testList.end())
		std::cerr << RED "Value is lost!" RESET << std::endl;
	end = std::clock();
	std::cout << WHITE "KEYWORD: " << GREEN "COMPLEXITY" RESET << std::endl;
	std::cout << ORANGE << "The " << GREEN "LIST " << ORANGE << "time to find is: " << YELLOW << (end - start) / CLOCKS_PER_SEC <<  ORANGE " s" << RESET << std::endl;
	std::vector<int>::iterator itV = testVector.begin();
	start = std::clock();
	while (itV != testVector.end())
	{
		if (*itV == value)
		{
			std::cout << GREEN "Value found: " << YELLOW <<  value << GREEN "!!!" << RESET << std::endl;
			break ;
		}
		++itV;
	}
	end = std::clock();
	if (itV == testVector.end())
                std::cerr << RED "Value is lost!" RESET << std::endl;
	std::cout << WHITE << "KEYWORD: " << GREEN "ORGANIZED" RESET << std::endl;
	std::cout << ORANGE << "The " << GREEN "VECTOR " << ORANGE << "time to find is: " << YELLOW << (end - start) / CLOCKS_PER_SEC <<  ORANGE " s" << RESET << std::endl;
}
