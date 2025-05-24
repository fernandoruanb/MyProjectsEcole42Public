/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:10:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/24 11:02:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int	a = 2;
	int	b = 3;

	::swap( a, b );
	std::cout << RED "a = " RESET << YELLOW << a << RESET << RED ", b = " RESET << YELLOW << b << RESET << std::endl;
	std::cout << BRIGHT_MAGENTA "min( a, b ) = " RESET << YELLOW << ::min( a, b ) << RESET << std::endl;
	std::cout << BRIGHT_MAGENTA "max( a, b ) = " RESET << YELLOW << ::max( a, b ) << RESET << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << RED "c = " RESET << YELLOW << c << RESET << RED ", d = " RESET << YELLOW << d << RESET << std::endl;
	std::cout << BRIGHT_MAGENTA "min( c, d ) = " RESET << YELLOW << ::min( c, d ) << RESET << std::endl;
	std::cout << BRIGHT_MAGENTA "max( c, d ) = " RESET << YELLOW << ::max( c, d ) << RESET << std::endl;
	return (0);
}
