/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:25:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 14:38:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	int	ShortSpan;
	int	LongSpan;
	unsigned int	index;

	try
	{
		Span a(10);
		//Span a(2);

		std::cout << BRIGHT_MAGENTA << std::string(12, '=') << "TEST 1" << std::string(12, '=') << std::endl;
		std::cout << std::string(30, '=') << RESET << std::endl;
		index = 1;
		std::cout << BRIGHT_WHITE "addNumber() TEST" RESET << std::endl << std::endl;
		while (index < 11)
		{
			a.addNumber(index * 2);
			index++;
		}
		ShortSpan = a.shortestSpan();
		LongSpan = a.longestSpan();

		std::cout << BRIGHT_YELLOW "shortestSpan() " << BRIGHT_WHITE "and " <<  BRIGHT_YELLOW " longestSpan() " << BRIGHT_WHITE "MAIN TEST RESET" << std::endl << std::endl;
		std::cout << WHITE "A Shortest Span: " RESET << YELLOW << ShortSpan << RESET << std::endl;
		std::cout << WHITE "A Longest Span: " RESET << YELLOW << LongSpan << RESET << std::endl;
		//a.addNumber(3);
		std::cout << BRIGHT_MAGENTA << std::string(30, '=')  << std::endl;
		std::cout << std::string(12, '=') << "TEST 2" << std::string(12, '=') << RESET << std::endl;
		Span b(a);
		Span c(10);
		c = b;
		index = 0;
		std::cout << BRIGHT_WHITE "Copy Constructor TEST ( B )" RESET << std::endl << std::endl;
		while (index < 5)
		{
				std::cout << ORANGE "B[" RESET << LIGHT_BLUE << index << ORANGE "]: " << YELLOW << b.getNumber()[index] << RESET << std::endl;
			index++;
		}
		std::cout << std::endl;
		index = 0;
		std::cout << BRIGHT_WHITE "Copy assignment TEST ( C )" RESET << std::endl << std::endl;
		while (index < 5)
		{
			std::cout << ORANGE "C[" << LIGHT_BLUE << index << ORANGE "]: " << YELLOW << c.getNumber()[index] << RESET << std::endl;
			index++;
		}
		std::cout << std::endl;
		ShortSpan = b.shortestSpan();
                LongSpan = b.longestSpan();
                std::cout << WHITE "B Shortest Span: " RESET << YELLOW << ShortSpan << RESET << std::endl;
                std::cout << WHITE "B Longest Span: " RESET << YELLOW << LongSpan << RESET << std::endl << std::endl;
		ShortSpan = c.shortestSpan();
                LongSpan = c.longestSpan();
                std::cout << WHITE "C Shortest Span: " RESET << YELLOW << ShortSpan << RESET << std::endl;
                std::cout << WHITE "C Longest Span: " RESET << YELLOW << LongSpan << RESET << std::endl;
		std::cout << BRIGHT_MAGENTA << std::string(30, '=') << RESET << std::endl;
		std::cout << BRIGHT_MAGENTA << std::string(12, '=') << "TEST 3" << std::string(12, '=') << std::endl;
		std::cout << BRIGHT_WHITE "OFFICIAL TEST" RESET << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << YELLOW << sp.shortestSpan() << RESET << std::endl;
		std::cout << YELLOW << sp.longestSpan() << RESET << std::endl;
		std::cout << BRIGHT_MAGENTA << std::string(30, '=') << RESET << std::endl;
		std::cout << BRIGHT_MAGENTA << std::string(12, '=') << "TEST 4" << std::string(12, '=') << std::endl;
		Span test(10);
		std::vector<int> values;
		index = 1;
		while (index < 11)
		{
			values.push_back(index * 3);
			index++;
		}
		std::cout << BRIGHT_GREEN "Adding range of values at the same time" << RESET << std::endl;
		std::cout << BRIGHT_WHITE "addRange() Test" << RESET << std::endl;
		test.addRange(values.begin(), values.end());
		index = 0;
		while (index < values.size())
		{
			std::cout << LIGHT_BLUE "values[" << ORANGE << index << "]: " << YELLOW << values[index] << RESET << std::endl;
			index++;
		}
		std::cout << BRIGHT_MAGENTA << std::string(30, '=') << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BRIGHT_MAGENTA << std::string(30, '=') << std::endl;
		std::cerr << RED << std::string(8, ' ') << "Error found!!!" RESET << std::endl;
		std::cout << BRIGHT_MAGENTA << std::string(30, '=') << RESET << std::endl;
	}
	return (0);
}
