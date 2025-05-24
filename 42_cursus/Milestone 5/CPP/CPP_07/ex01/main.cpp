/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:57:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/24 12:59:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void	get_ascii(char const &letter)
{
	std::cout << letter << ": " << static_cast<int>(letter) << std::endl;
}

static void	print_letter(char const &letter)
{
	if (letter >= 'a' && letter <= 'z')
	       std::cout << static_cast<char>(letter - 32);
	else if (letter >= 'A' && letter <= 'Z')
		std::cout << static_cast<char>(letter + 32);
	else
		std::cout << BRIGHT_GREEN << letter << RESET << std::endl;
}

static void	print_numbers(int const &number)
{
	std::cout << GREEN << number << RESET << std::endl;
}

static void	pow2(int &number)
{
	number *= 2;
	std::cout << GREEN << number << RESET << std::endl;
}

int	main(void)
{
	std::string	text;
	int numbers[8] = {33, 34, 35, 36, 37, 48, 70, 78};

	std::cout << MAGENTA "======== TEST 1 =======" RESET << std::endl;
	text = "myFriEnd";
	::iter(text.c_str(), text.size(), &print_letter);
	std::cout << std::endl;
	std::cout << YELLOW << text << RESET << std::endl;
	std::cout << MAGENTA "=======================" RESET << std::endl << std::endl;
	std::cout << MAGENTA "======== TEST 2 =======" RESET << std::endl;
	::iter(text.c_str(), text.size(), &get_ascii);
	std::cout << MAGENTA "=======================" RESET << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << MAGENTA "======== TEST 3 =======" RESET << std::endl;
	::iter("iu", 2, &get_ascii);
	std::cout << MAGENTA "=======================" RESET << std::endl;
	std::cout << std::endl;
	std::cout << MAGENTA "======== TEST 4 ======" RESET << std::endl;
	::iter(numbers, 8, &print_numbers);
	std::cout << std::endl;
	::iter(numbers, 8, &pow2);
	std::cout << MAGENTA "======================" RESET << std::endl;
}
