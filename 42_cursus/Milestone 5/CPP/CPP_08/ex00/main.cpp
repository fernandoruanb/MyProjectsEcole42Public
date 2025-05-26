/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:16:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 14:40:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> values;
	//std::vector<char>	values;
	//std::vector<double>	values;
	//std::vector<float>	values;
	//std::vector<std::string>	values;

	int	result;
	int	value;

	std::cout << std::endl;
	std::cout << BRIGHT_WHITE << "( " << LIGHT_BLUE << std::string(6, ' ') << "AMAZING CPP 08 TESTER =D" << BRIGHT_WHITE << std::string(6, ' ') << ")" << RESET << std::endl;
	try
	{
		values.push_back(12);
		values.push_back('a');
		values.push_back(32);
		value = 97;
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
		std::cerr << BRIGHT_RED << std::string(8, ' ') << "Value not found D= " << YELLOW << value << RESET << std::endl;
		std::cerr << BRIGHT_MAGENTA << std::string(40, '=') << RESET << std::endl;
	}
	return (0);
}
