/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:35:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 16:57:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include "colours.hpp"
# include <vector>
# include <exception>
# include <algorithm>
# include <iostream>
# include <string>

template<typename T>
typename T::value_type easyfind(T const &number, int value)
{
	typename T::const_iterator it = number.begin();
	typename T::const_iterator ite = number.end();
	typename T::const_iterator result;

	result = std::find(it, ite, value);
	if (*result == value)
		return (*it);
	else
		throw std::exception();
}

#endif /* EASYFIND_HPP */
