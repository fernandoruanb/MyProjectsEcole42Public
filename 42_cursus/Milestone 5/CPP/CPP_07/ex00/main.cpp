/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:10:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 12:55:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int	a;
	int	b;
	int	result;

	a = 2;
	b = 3;
	swap(a, b);
	result = my_max(a, b);
	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "MAX: " << result << std::endl;
	result = my_min(a, b);
	std::cout << "MIN: " << result << std::endl;
	return (0);
}
