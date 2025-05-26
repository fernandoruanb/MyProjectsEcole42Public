/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:36:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/25 17:47:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>
# include "colours.hpp"

template<typename T>
class LabClass: public std::stack<T>
{
	public:
		LabClass(void)
		{
			std::cout << BRIGHT_GREEN "Lab constructor called" RESET << std::endl;
		}
		~LabClass(void)
		{
			std::cout << BRIGHT_GREEN "Lab destructor called" RESET << std::endl;
		}
};

#endif /* STACK_HPP */
