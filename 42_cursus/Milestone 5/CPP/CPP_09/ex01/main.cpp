/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:39:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/02 12:27:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	int	number;
	std::stack<int> base;
	long long	index;
	int	result;

	if (argc != 2)
	{
		std::cerr << "Error: give one and only an argument, please" << std::endl;
		return (1);
	}
	result = 0;
	index = 0;
	while (argv[1][index] != '\0')
	{
		if (argv[1][index] == ' ')
		{
			++index;
			continue ;
		}
		else if (argv[1][index] >= '0' && argv[1][index] <= '9')
		{
			if (argv[1][index + 1] != '\0')
			{
				if (argv[1][index + 1] >= '0' && argv[1][index] <= '9')
				{
					std::cerr << "Error: Only numbers with one unit are accepted" << std::endl;
					return (1);
				}
			}
			std::string token(1, argv[1][index]);
			std::stringstream ss(token);
			ss >> number;
			base.push(number);
		}
		else if (argv[1][index] == '*' || argv[1][index] == '/' || argv[1][index] == '+' || argv[1][index] == '-')
		{
			if (!process(argv[1][index], base, &result))
			{
				std::cerr << "Error: invalid process detected!" << std::endl;
				return (1);
			}
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		++index;
	}
	std::cout << base.top() << std::endl;
	return (0);
}
