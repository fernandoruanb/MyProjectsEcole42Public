/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:00:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/03 10:45:00 by fruan-ba         ###   ########.fr       */
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
	std::list<int>	pmergeMe;
	std::vector<int> pmergeMe2;

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
				std::cerr << RED "Error: invalid input detected => " << BRIGHT_YELLOW << argv[count][index] << RESET << std::endl;
				return (1);
			}
			if (flag == 1)
				index += checker;
			else
				++index;
		}
		count++;
	}
	fordJohnsonList(pmergeMe);
	fordJohnsonVector(pmergeMe2);
	/*std::vector<int>::const_iterator itv = pmergeMe2.begin();
	std::list<int>::const_iterator it = pmergeMe.begin();
	std::cout << "LIST" << std::endl;
	while (it != pmergeMe.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "VECTOR" << std::endl;
	while (itv != pmergeMe2.end())
	{
		std::cout << *itv << std::endl;
		++itv;
	}*/
	return (0);
}
