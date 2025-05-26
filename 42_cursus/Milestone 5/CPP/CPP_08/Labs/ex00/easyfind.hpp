/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:35:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 14:23:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "colours.hpp"
# include <vector>
# include <exception>
# include <iostream>
# include <string>

template<typename T>
typename T::value_type easyfind(T const &number, int value)
{
	typename T::const_iterator it = number.begin();

	while (it != number.end())
	{
		if (*it == value)
			return (*it);
		++it;
	}
	throw std::exception();
}

#endif /* EASYFIND_HPP */
