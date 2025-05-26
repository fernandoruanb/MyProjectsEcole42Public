/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LabClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:55:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/25 18:51:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABCLASS_HPP
# define LABCLASS_HPP

# include "colours.hpp"
# include <iostream>
# include <vector>
# include <stack>
# include <algorithm>

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
			std::cout << BRIGHT_RED "Lab destructor called" RESET << std::endl;
		}
		typedef typename std::stack<T>::container_type::iterator iterator;

			iterator begin() { return this->c.begin(); }
			iterator end() { return this->c.end(); }
};

#endif /* LABCLASS_HPP */
