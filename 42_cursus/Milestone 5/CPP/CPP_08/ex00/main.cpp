/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:16:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/24 20:35:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> values;
	int	result;
	int	value;

	std::cout << std::endl;
	std::cout << LIGHT_BLUE << std::string(7, ' ') << "AMAZING CPP 07 TESTER =D" RESET << std::endl;
	try
	{
		values.push_back(1);
		values.push_back(2);
		values.push_back(3);
		value = 2;
		result = easyfind(values, value);
		std::cout << BRIGHT_MAGENTA << std::string(40, '=') << RESET << std::endl;
		std::cout << BRIGHT_GREEN << std::string(10, ' ') <<  "Value found: " RESET << BRIGHT_YELLOW << value << RESET << std::endl;
		std::cout << BRIGHT_MAGENTA << std::string(40, '=') << RESET << std::endl;
		value = 10;
		result = easyfind(values, value);
	}
	catch (std::exception &exception)
	{
		std::cerr << std::endl;
		std::cerr << BRIGHT_MAGENTA << std::string(40, '=') << RESET << std::endl;
		std::cerr << BRIGHT_RED << std::string(10, ' ') << "Value not found D= " << YELLOW << value << RESET << std::endl;
		std::cerr << BRIGHT_MAGENTA <<  std::string(40, '=') << RESET << std::endl;
	}
	return (0);
}
