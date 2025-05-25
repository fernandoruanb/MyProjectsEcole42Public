/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:25:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/24 21:48:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int	main(void)
{
	try
	{
		Span a(2);

		std::cout << BRIGHT_MAGENTA << std::string(30, '=') << std::endl;
		a.addNumber(1);
		a.addNumber(2);
		//a.addNumber(3);
		std::cout << BRIGHT_MAGENTA << std::string(30, '=') << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << BRIGHT_MAGENTA << std::string(30, '=') << std::endl;
		std::cerr << RED << std::string(8, ' ') << "Error found!!!" RESET << std::endl;
		std::cout << BRIGHT_MAGENTA << std::string(30, '=') << RESET << std::endl;
	}
	return (0);
}
