/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:08:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/25 17:35:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>
# include <algorithm>
# include <iostream>
# include "colours.hpp"

template<typename T>
class	MutantStack: public std::stack<T>
{
	private:

	public:
		MutantStack(void)
		{
			std::cout << BRIGHT_GREEN "Default input constructor called" RESET << std::endl;
		}
		~MutantStack(void)
		{
			std::cout << BRIGHT_RED "Destructor called" RESET << std::endl;
		}
		MutantStack& operator=(const MutantStack& other)
		{
			return (*this);
		}
		MutantStack(const MutantStack &other)
		{
			std::cout << BRIGHT_GREEN "Copy constructor called" RESET << std::endl;
		}
		template typename std::stack<T>::container_type::iterator iterator
		{
			iterator start = return (this->c.begin());
			iterator end = return (this->c.end());
		}
};
template<typename OUT>
std::ostream& operator<<(std::ostream& out, const MutantStack<OUT>& other)
{
	typename MutantStack<OUT>::const_iterator start = other.begin();
	typename MutantStack<OUT>::const_iterator end = other.end();

	while (start != end)
	{
		out << *start << std::endl;
		++start;
	}
	return (out);
}

#endif /* MUTANTSTACK_HPP */
