/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:08:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/25 14:14:36 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>
# include <algorithm>
# include <iostream>

template<typename T>
class	MutantStack: public std::stack<T>
{
	private:

	public:
		MutantStack(void);
		~MutantStack(void);
		MutantStack& operator=(const MutantStack& other);
		MutantStack(const MutantStack &other);
};
std::ostream& operator<<(std::ostream& out, const MutantStack<T>& other);

#endif /* MUTANTSTACK_HPP */
