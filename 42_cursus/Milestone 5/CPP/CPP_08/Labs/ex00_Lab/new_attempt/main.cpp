/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:48:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 12:52:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> values;
	int	target;

	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	target = 3;

	try
	{
		easyfind(values, target);
		target = 4;
		easyfind(values, target);
	}
	catch (std::exception &exception)
	{
		std::cerr << "Unfortunately, we didn't find the value" << std::endl;
	}
	return (0);
}
