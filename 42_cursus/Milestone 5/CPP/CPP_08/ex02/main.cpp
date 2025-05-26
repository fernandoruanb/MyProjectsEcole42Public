/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:44:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 09:48:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << ORANGE "TOP Value: " << YELLOW << mstack.top() << RESET << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}
