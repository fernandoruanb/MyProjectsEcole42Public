/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfinder.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:54:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 12:08:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFINDER_HPP
# define EASYFINDER_HPP

# include <vector>
# include <iostream>
# include <exception>

template<typename find>
typename find::value_type easyfinder(find const &other, int value)
{
	typename find::const_iterator it;

	it = other.begin();
	while (it != other.end())
	{
		if (*it == value)
		{
			std::cout << "We found " << value << std::endl;
			return (*it);
		}
		++it;
	}
	throw std::exception();
};

#endif /* EASYFINDER_HPP */
