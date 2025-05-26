/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:01:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/25 18:55:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LabClass.hpp"

int	main(void)
{
	LabClass<int>	target;
//	LabClass<int>::iterator it = target.begin();
//	LabClass<int>::iterator ite = target.end();

	target.push(42);
	std::cout << YELLOW << target.top() << RESET << std::endl;
	target.push(84);
	std::cout << YELLOW << target.top() << RESET << std::endl;
	target.push(1);
	LabClass<int>::iterator it = target.begin();
	LabClass<int>::iterator ite = target.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return (0);
}
