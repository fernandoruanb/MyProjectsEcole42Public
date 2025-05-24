/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:35:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/24 18:52:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <exception>

static int	findVector(std::vector<int> &box, int target)
{
	std::vector<int>::iterator it = box.begin();
	while (it != box.end())
	{
		if (*it == target)
		{
			std::cout << "We found the target " << target << "in the box" << std::endl;
			return (*it);
		}
		++it;
	}
	throw std::exception();
	return (1);
}

int	main(void)
{
	int	result;

	try
	{
		std::vector<int> box = {10, 20, 30};
		result = findVector(box, 40);
		std::cout << "The result is: " << result << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cerr << "We didn't find anything on the box" << std::endl;
	}
	return (0);
}
