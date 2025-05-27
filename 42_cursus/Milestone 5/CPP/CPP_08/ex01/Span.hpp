/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:45:41 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/27 09:55:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <algorithm>
# include <vector>
# include "colours.hpp"

class Span
{
	private:
		std::vector<int> number;
		unsigned int	capacity;
	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span& operator=(const Span &other);
		Span(const Span &other);
		int	shortestSpan(void) const;
		int	longestSpan(void) const;
		void	addNumber(int number);
		const std::vector<int>& getNumber(void) const;
		unsigned int	getCapacity(void) const;
		unsigned int	getSize(void) const;
		template<typename iterator>
		void	addRange(iterator begin, iterator end);
};
std::ostream& operator<<(std::ostream &out, const Span &other);
template<typename iterator>
void Span::addRange(iterator begin, iterator end)
{
	if ((unsigned long)(std::distance(begin, end)) > (unsigned long)(capacity - number.size()))
		throw std::exception();
	number.insert(number.end(), begin, end);
}

#endif /* SPAN_HPP */
