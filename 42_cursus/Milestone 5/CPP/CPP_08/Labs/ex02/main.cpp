/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:44:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 13:57:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	mstack;
	MutantStack<int>	assignmentStack;
	std::list<int> mlist;
	long long	index;

	mstack.push(5);
	mstack.push(17);

	std::cout << BRIGHT_WHITE "TOP Value: " << YELLOW << mstack.top() << RESET << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	MutantStack<int>	copyMstack(mstack);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	index = 0;
	std::cout << BRIGHT_MAGENTA << std::string(12, '=') << "TEST 1" << std::string(12, '=') << RESET << std::endl;
	while (it != ite)
	{
		std::cout << ORANGE "MSTACK[" << WHITE << index << LIGHT_BLUE "]: " << YELLOW << *it << RESET << std::endl;
		++index;
		++it;
	}
	std::cout << BRIGHT_MAGENTA << std::string(30, '=') << RESET << std::endl;
	mlist.push_back(5);
	mlist.push_back(17);
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);

	MutantStack<int>::iterator copyIt;
	MutantStack<int>::iterator copyIte;

	std::list<int>::iterator listIt;
	std::list<int>::iterator listIte;

	listIt = mlist.begin();
	listIte = mlist.end();

	copyIt = copyMstack.begin();
	copyIte = copyMstack.end();

	std::cout << std::endl;
	std::cout << BRIGHT_MAGENTA << std::string(12, '=') << "TEST 2" << std::string(12, '=') << RESET << std::endl;
	index = 0;
	while (listIt != listIte)
	{
		std::cout << ORANGE "MLIST[" << WHITE << index << LIGHT_BLUE "]: " << YELLOW << *listIt << RESET << std::endl;
		++index;
		++listIt;
	}
	std::cout << BRIGHT_MAGENTA << std::string(30, '=') << RESET << std::endl;
	std::cout << BRIGHT_MAGENTA << std::string(12, '=') << "TEST 3" << std::string(12, '=') << RESET << std::endl;
	
	index = 0;
	while (copyIt != copyIte)
	{
		std::cout << ORANGE "copyMstack[" << WHITE << index << LIGHT_BLUE "]: " << YELLOW << *copyIt << RESET << std::endl;
		++copyIt;
		++index;
	}
	std::cout << BRIGHT_MAGENTA << std::string(30, '=') << std::endl;
	std::cout << BRIGHT_MAGENTA << std::string(12, '=') << "TEST 4" << std::string(12, '=') << std::endl;
	assignmentStack = mstack;

	copyIt = assignmentStack.begin();
	copyIte = assignmentStack.end();
	index = 0;

	while (copyIt != copyIte)
	{
		std::cout << ORANGE "assignmentStack[" << WHITE << index << LIGHT_BLUE  "]: " << YELLOW << *copyIt << RESET << std::endl;
		++copyIt;
		++index;
	}
	std::cout << BRIGHT_MAGENTA << std::string(30, '=') << std::endl;

	std::stack<int> s(mstack);

	//std::stack<int>::iterator stackIt;
	//std::stack<int>::iterator stackIte;
	return (0);
}
