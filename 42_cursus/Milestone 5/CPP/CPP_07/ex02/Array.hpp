/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:54:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/22 15:59:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <stdexcept>
# include "colours.hpp"

template<typename A>
class Array
{
	private:
		A* data;
		unsigned int	length;
	public:
		template<typename A>
		Array(void): data(NULL), length(0)
		{
			std::cout << GREEN << "Default constructor called" RESET << std::endl;
		}
		template<typename A>
		Array(unsigned int len): data(NULL), length(len)
		{
			std::cout << BRIGHT_GREEN << "Default input constructor called " RESET << std::endl;
		}
		template<typename A>
		~Array(void)
		{
			std::cout << BLUE << "Destructor called " RESET << std::endl;
		}
		template<typename A>
		Array& operator=(const Array &another)
		{
			if (this != &another)
			{
				data = another.get_data();
				length = another.get_length();
			}
			return (*this);
		}
		template<typename A>
		A& operator[](unsigned int index)
		{
			if (index >= this->get_length())
				throw std::runtime_error("Operator[] Index Error");
			return (this->data[index]);
		}
		A const& operator[](unsigned int index) const
		{
			if (index >= this->get_length())
				throw std::runtime_error("Operator[] Index Error");
			return (this->data[index]);
		}
		template<typename A>
		A*	get_data(void)
		{
			return (this->data);
		}
		template<typename A>
		A const *get_data(void) const
		{
			return (this->data);
		}
		template<typename A>
		unsigned int	size(void) const
		{
			return (this->length);
		}
		template<typename A>
		unsigned int	get_length(void) const
		{
			return (this->length);
		}
		template<typename A>
		Array(const Array &another): data(another.get_data()), length(another.size())
		{
			std::cout << BRIGHT_MAGENTA "Copy constructor called" RESET << std::endl;
		}
};
template<typename OUT>
std::ostream& operator<<(std::ostream& out, const Array<OUT> &another)
{
	std::cout << "The array: " << another.get_data();
}

#endif /* ARRAY_HPP */
