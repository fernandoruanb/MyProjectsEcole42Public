/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:58:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 12:10:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfinder.hpp"

int	main(void)
{
	std::vector<char> values;
	int	target;

	values.push_back('p');
	values.push_back('a');
	values.push_back('j');
	target = 97;

	try
	{
		easyfinder(values, target);
		target = 30;
		easyfinder(values, target);
	}
	catch (std::exception &e)
	{
		std::cerr << "Mistake found" << std::endl;
	}
	return (0);
}
