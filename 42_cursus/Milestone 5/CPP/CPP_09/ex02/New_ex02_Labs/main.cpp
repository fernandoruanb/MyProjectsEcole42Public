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
	std::cout << GREEN "Parser OK!" RESET << std::endl;
	return (1);
}

static void	mountVectorEven(std::vector<unsigned int> vectorBase, std::vector<unsigned int> &vectorHigh, std::vector<unsigned int> &vectorLow)
{
	std::vector<unsigned int>::iterator itv = vectorBase.begin();
	std::vector<unsigned int>::iterator nv;

	while (itv != vectorBase.end())
	{
		nv = itv;
		++nv;
		if (nv == vectorBase.end())
		{
			vectorLow.push_back(*itv);
			break ;
		}
		if (*itv < *nv)
		{
			vectorLow.push_back(*itv);
			vectorHigh.push_back(*nv);
		}
		else
		{
			vectorHigh.push_back(*nv);
			vectorLow.push_back(*itv);
		}
		itv = nv;
		++itv;
	}
}

static void	mountListEven(std::list<unsigned int> listBase, std::list<unsigned int> &listHigh, std::list<unsigned int> &listLow)
{
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

	if (!parser(argc, argv, vectorBase, listBase))
	{
		std::cerr << RED "Error: Invalid input detected." RESET << std::endl;
		return (1);
	}
	mountVectorEven(vectorBase, vectorHigh, vectorLow);
	sortHighVector(vectorHigh);
	mountListEven(listBase, listHigh, listLow);
	sortHighList(listHigh);
	return (0);
}
