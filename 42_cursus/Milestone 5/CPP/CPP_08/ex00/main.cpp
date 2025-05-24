/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:16:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/24 19:34:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> values;
	int	result;
	int	value;

	try
	{
		values.push_back(1);
		values.push_back(2);
		values.push_back(3);
		value = 2;
		result = easyfind(values, value);
		std::cout << BRIGHT_MAGENTA << std::string(40, '=') << RESET << std::endl;
		std::cout << BRIGHT_GREEN "We found the value: " RESET << BRIGHT_YELLOW << value << RESET << std::endl;
		std::cout << BRIGHT_MAGENTA << std::string(40, '=') << RESET << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cerr << BRIGHT_MAGENTA << std::string(40, '=') << RESET << std::endl;
		std::cerr << BRIGHT_RED "We didn't find the value D=" RESET << std::endl;
		std::cerr << BRIGHT_MAGENTA <<  std::string(40, '=') << RESET << std::endl;
	}
	return (0);
}
