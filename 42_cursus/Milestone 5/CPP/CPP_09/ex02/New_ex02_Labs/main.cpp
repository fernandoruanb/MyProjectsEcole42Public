/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:54:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/06 17:54:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "PmergeME.hpp"

static bool	ft_atoi_check(const char *argv)
{
	long	result;
	long	signal;
	long	index;

	result = 0;
	signal = 1;
	index = 0;
	while (argv[index] == '\n' || argv[index] == '\f' || argv[index] == '\v'
		|| argv[index] == '\t' || argv[index] == '\r')
		index++;
	while (argv[index] >= '0' && argv[index] <= '9')
	{
		result *= 10;
		result += argv[index] - '0';
		if (result > INT_MAX)
			return (0);
		index++;
	}
	return (1);
}

static bool	parser(int argc, char **argv, std::vector<unsigned int> &vectorBase, std::list<unsigned int> &listBase)
{
	long long	count;
	long long	index;
	long long	value;
	std::string	checker;

	count = 1;
	while (count < argc)
	{
		index = 0;
		if (argv[count][0] == '\0')
			return (0);
		checker = argv[count];
		while (argv[count][index] != '\0')
		{
			if (argv[count][index] >= '0' && argv[count][index] <= '9')
					index++;
			else
				return (0);
		}
		if (!ft_atoi_check(argv[count]))
			return (0);
		std::stringstream ss(argv[count]);
		ss >> value;
		vectorBase.push_back(value);
		listBase.push_back(value);
		count++;
	}
	return (1);
}

static void	mountVectorEven(std::vector<unsigned int> vectorBase, std::vector<unsigned int> &vectorHigh, std::vector<unsigned int> &vectorLow)
{
	vectorLow.clear();
	vectorHigh.clear();
	long long	index;

	index = 0;
	while (index < vectorBase.size())
	{
		if (index + 1 >= vectorBase.size())
		{
			vectorLow.push_back(vectorBase[index]);
			break ;
		}
		else if (vectorBase[index] < vectorBase[index + 1])
		{
			vectorLow.push_back(vectorBase[index]);
			vectorHigh.push_back(vectorBase[index + 1]);
		}
		else
		{
			vectorLow.push_back(vectorBase[index + 1]);
			vectorHigh.push_back(vectorBase[index]);
		}
		index += 2;
	}
}

static void	mountListEven(std::list<unsigned int> listBase, std::list<unsigned int> &listHigh, std::list<unsigned int> &listLow)
{
	listLow.clear();
	listHigh.clear();
	std::list<unsigned int>::iterator itl = listBase.begin();
	std::list<unsigned int>::iterator nl;

	while (itl != listBase.end())
	{
		nl = itl;
		++nl;
		if (nl == listBase.end())
		{
			listLow.push_back(*itl);
			break ;
		}
		else if (*itl < *nl)
		{
			listHigh.push_back(*nl);
			listLow.push_back(*itl);
		}
		else
		{
			listHigh.push_back(*itl);
			listLow.push_back(*nl);
		}
		itl = nl;
		++itl;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << RED "Error: You need to put arguments" RESET << std::endl;
		return (1);
	}

	std::vector<unsigned int> vectorBase;
	std::list<unsigned int> listBase;
	std::vector<unsigned int> vectorHigh;
	std::vector<unsigned int> vectorLow;
	std::list<unsigned int> listHigh;
	std::list<unsigned int> listLow;
	std::vector<unsigned int> jacobVector;
	std::vector<unsigned int> orderVector;
	std::list<unsigned int> orderList;
	std::list<unsigned int> jacobList;

	if (!parser(argc, argv, vectorBase, listBase))
	{
		std::cerr << RED "Error: Invalid input detected." RESET << std::endl;
		return (1);
	}
	mountVectorEven(vectorBase, vectorHigh, vectorLow);
	sortHighVector(vectorHigh);
	mountListEven(listBase, listHigh, listLow);
	sortHighList(listHigh);
	generateVectorJacobsthal(jacobVector, orderVector, vectorLow.size());
	generateListJacobsthal(jacobList, orderList, listLow.size());
	doTheMagicVector(vectorHigh, vectorLow, orderVector);
	doTheMagicList(listHigh, listLow, orderList);
	
	// Comunicate the results to USER

	std::cout << BRIGHT_MAGENTA "Before: " RESET;
	showVector(vectorBase);
	std::cout << BRIGHT_MAGENTA "Before: " RESET;
	showList(listBase);
	std::cout << BRIGHT_MAGENTA "After: " RESET;
	showVector(vectorHigh);
	std::cout << BRIGHT_MAGENTA "After: " RESET;
	showList(listHigh);
	isVectorSorted(vectorHigh);
	isListSorted(listHigh);
	return (0);
}
