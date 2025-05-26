/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:09:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 09:25:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LabClass.hpp"

int	main(void)
{
	LabClass<int> test;

	//LabClass<int>::iterator it = test.begin();
	//LabClass<int>::iterator ite = test.end();

	test.push(42);
	test.push(12);
	test.push(10);
	test.push(11);

	LabClass<int>::iterator it = test.begin();
	LabClass<int>::iterator ite = test.end();

	std::cout << ORANGE "TOP Value: " << YELLOW << test.top() << RESET << std::endl;
	test.pop();
	std::cout << ORANGE "TOP Value: " << YELLOW << test.top() << RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(test);
	return (0);
}
