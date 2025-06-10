/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:39:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/10 14:39:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	long long	number;
	int	flag;
	std::stack<int> base;
	long long	index;
	char	another;
	long long	result;

	if (argc != 2)
	{
		std::cerr << RED "Error: give one and only an argument, please" RESET << std::endl;
		return (1);
	}
	flag = 0;
	if (argv[1][0] == '\0')
	{
		std::cerr << RED "Error: empty input is invalid" RESET << std::endl;
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
				if (argv[1][index + 1] >= '0' && argv[1][index + 1] <= '9')
				{
					while (argv[1][index] && argv[1][index] == '0')
						index++;
					if (argv[1][index] != ' ')
					{
						if (argv[1][index] >= '0' && argv[1][index] <= '9')
						{
							another = argv[1][index + 1];
							if (another >= '0' && another <= '9')
							{
								std::cerr << RED "Error: Only numbers with one unit are accepted" RESET << std::endl;
								return (1);
							}
							continue ;
						}
						std::cerr << RED "Error: Only numbers with one unit are accepted" RESET << std::endl;
						return (1);
					}
					else
						--index;
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
				return (1);
			flag = 1;
		}
		else
		{
			std::cerr << RED "Error" RESET << std::endl;
			return (1);
		}
		++index;
	}
	if (base.size() == 1 && flag == 1)
		std::cout << LIGHT_GREEN << base.top() << RESET << std::endl;
	else if (flag == 0)
	{
		std::cerr << RED "Error: where are the operators???" RESET << std::endl;
		return (1);
	}
	else
	{
		std::cerr << RED "Error: the stack must be only one number in the final" RESET << std::endl;
		return (1);
	}
	return (0);
}
