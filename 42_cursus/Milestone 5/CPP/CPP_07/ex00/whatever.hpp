/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:00:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 12:55:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename S>
void swap(S& a, S& b)
{
	S temp = a;
	a = b;
	b = temp;
}

template<typename MAX>
MAX my_max(const MAX& a, const MAX& b)
{
	if (a > b)
		return (a);
	return (b);
}

template<typename MIN>
MIN my_min(const MIN& a, const MIN& b)
{
	if (a < b)
		return (a);
	return (b);
}

#endif /* WHATEVER_HPP */
