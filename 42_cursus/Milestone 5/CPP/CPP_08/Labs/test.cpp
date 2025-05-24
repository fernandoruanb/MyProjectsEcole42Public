/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:00:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/24 19:01:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <exception>
#include <iostream>

static int	findVector(std::vector<int> box, int target)
{
	std::vector<int>::iterator it = box.begin();

	while (it != box.end())
	{
		if (*it == target)
			return (*it);
		++it;
	}
	throw std::exception();
	return (1);
}

int	main(void)
{
	std::vector<int> box = {1, 2, 3, 4};
	int	result;

	try
	{
		result = findVector(box, 34);
		std::cout << "Achamos o valor " << result << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cerr << "Não achamos o valor" << std::endl;
	}
	return (0);
}
