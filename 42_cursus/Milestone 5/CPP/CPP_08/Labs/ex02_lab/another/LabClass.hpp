/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LabClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:06:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 09:20:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABCLASS_HPP
# define LABCLASS_HPP

# include <iostream>
# include <stack>
# include <vector>
# include <algorithm>
# include "colours.hpp"

template<typename T>
class LabClass: public std::stack<T>
{
	public:
		LabClass(void)
		{
			std::cout << BRIGHT_GREEN "Default Constructor called" RESET << std::endl;
		}
		~LabClass(void)
		{
			std::cout << BRIGHT_RED "Destructor called" RESET << std::endl;
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		
		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }
};

#endif /* LABCLASS_HPP */
