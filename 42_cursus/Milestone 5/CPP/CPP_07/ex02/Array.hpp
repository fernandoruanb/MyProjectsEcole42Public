/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:54:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/24 18:00:54 by fruan-ba         ###   ########.fr       */
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
		Array(void): data(new A[0]), length(0)
		{
			std::cout << GREEN << "Default constructor called" RESET << std::endl;
		}
		Array(unsigned int len): data(new A[len]), length(len)
		{
			std::cout << BRIGHT_GREEN << "Default input constructor called " RESET << std::endl;
		}
		~Array(void)
		{
			std::cout << RED << "Destructor called " RESET << std::endl;
			delete [] this->data;
		}
		Array& operator=(const Array &another)
		{
			unsigned int	index;

			std::cout << BRIGHT_YELLOW "Copy assignment operator called" RESET << std::endl;
			index = 0;
			if (this != &another)
			{
				delete [] this->data;
				this->data = new A[another.size()];
				while (index < another.size())
				{
					data[index] = another[index];
					index++;
				}
				length = another.get_length();
			}
			return (*this);
		}
		A& operator[](unsigned int index)
		{
			if (index >= this->get_length())
				throw std::exception();
			return (this->data[index]);
		}
		A const& operator[](unsigned int index) const
		{
			if (index >= this->get_length())
				throw std::exception();
			return (this->data[index]);
		}
		A*	get_data(void)
		{
			return (this->data);
		}
		A const *get_data(void) const
		{
			return (this->data);
		}
		unsigned int	size(void) const
		{
			return (this->length);
		}
		unsigned int	get_length(void) const
		{
			return (this->length);
		}
		Array(const Array &another): data(new A[another.size()]), length(another.size())
		{
			unsigned int 	index;

			index = 0;
			while (index < another.size())
			{
				data[index] = another[index];
				index++;
			}
			std::cout << BRIGHT_MAGENTA "Copy constructor called" RESET << std::endl;
		}
};
template<typename OUT>
std::ostream& operator<<(std::ostream& out, const Array<OUT> &another)
{
	out << "The array: " << YELLOW << another.get_data() << RESET << " Length: " << YELLOW << another.get_length() << RESET;
	return (out);
}

#endif /* ARRAY_HPP */
