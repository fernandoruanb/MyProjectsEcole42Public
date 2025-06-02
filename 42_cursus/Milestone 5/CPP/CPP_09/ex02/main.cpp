/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:00:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/02 18:23:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeME.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
	{
		std::cerr << RED "Error: insufficient arguments" RESET << std::endl;
		return (1);
	}
	long long	index;
	long long	count;
	long long	num;
	std::list<int>	pmergeMe;

	index = 0;
	count = 1;
	while (count < argc)
	{
		index = 0;
		while (argv[count][index] != '\0')
		{
			if (argv[count][index] == ' ')
			{
				++index;
				continue ;
			}
		
			if (argv[count][index] >= '0' && argv[count][index] <= '9')
			{
				std::string	token(1, argv[count][index]);
				std::stringstream ss(token);
				ss >> num;
				pmergeMe.push_back(num);
			}
			else
			{
				std::cerr << RED "Error: invalid input detected => " << BRIGHT_YELLOW << argv[count][index] << RESET << std::endl;
				return (1);
			}
			++index;
		}
		count++;
	}
	return (0);
}
