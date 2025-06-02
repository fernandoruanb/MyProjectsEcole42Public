/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:02:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/02 14:44:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void	subtraction(int n1, int n2, std::stack<int> &base, long long *result)
{
	*result = n1 - n2;
	base.push(*result);
}

static void	division(int n1, int n2, std::stack<int> &base, long long *result)
{
	if (n2 == 0)
	{
		std::cerr << RED "Error: Division by Zero Error" RESET << std::endl;
		return ;
	}
	*result = n1 / n2;
	base.push(*result);
}

static void	addition(int n1, int n2, std::stack<int> &base, long long *result)
{
	*result = n1 + n2;
	base.push(*result);
}

static void	multiplication(int n1, int n2, std::stack<int> &base, long long *result)
{
	*result = n1 * n2;
	base.push(*result);
}

bool	process(char magic, std::stack<int> &base, long long *result)
{
	int	n1;
	int	n2;
	int	index;
	const char operators[4] = {'*', '/', '-', '+'};

	if (base.size() == 0 || base.size() < 2)
	{
		std::cerr << RED "Error: insufficient operands" RESET << std::endl;
		return (0);
	}

	void (*methods[4])(int, int, std::stack<int>&, long long*) = {
		&multiplication,
		&division,
		&subtraction,
		&addition,
	};

	index = 0;
	n2 = base.top();
	base.pop();
	n1 = base.top();
	base.pop();
	while (index < 4)
	{
		if (magic == operators[index])
		{
			methods[index](n1, n2, base, result);
			if (n2 == 0  && magic == '/')
				return (0);
			return (1);
		}
		index++;
	}
	if (index == 4)
	{
		std::cerr << RED "Error: invalid operator" RESET << std::endl;
		return (0);
	}
	return (1);
}
