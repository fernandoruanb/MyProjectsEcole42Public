/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:45:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/26 12:57:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <iostream>

template<typename find>
typename find::value_type easyfind(find const &other, int value)
{
	typename find::const_iterator it;

	it = other.begin();
	while (it != other.end())
	{
		if (*it == value)
		{
			std::cout << "We found the value " << value << std::endl;
			return (*it);
		}
		++it;
	}
	throw std::exception();
};
#endif /* EASYFIND_HPP */
