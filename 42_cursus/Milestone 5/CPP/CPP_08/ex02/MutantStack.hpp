/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:36:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 09:51:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <vector>
# include <algorithm>
# include <iostream>
# include <stack>
# include "colours.hpp"

template<typename T>
class	MutantStack: public std::stack<T>
{
	public:
		MutantStack(void)
		{
			std::cout << BRIGHT_GREEN "Default constructor called" << RESET << std::endl;
		}
		~MutantStack(void)
		{
			std::cout << BRIGHT_RED "Destructor called" << RESET << std::endl;
		}
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};
template<typename OUT>
std::ostream& operator<<(std::ostream &out, const MutantStack<OUT> &other)
{
	(void)other;
	out << "There is a MutantStack =D" << std::endl;
	return (out);
}

#endif /* MUTANTSTACK_HPP */
