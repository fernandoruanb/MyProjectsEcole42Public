/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:00:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 12:57:49 by fruan-ba         ###   ########.fr       */
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
MAX max(const MAX& a, const MAX& b)
{
	if (a > b)
		return (a);
	return (b);
}

template<typename MIN>
MIN min(const MIN& a, const MIN& b)
{
	if (a < b)
		return (a);
	return (b);
}

#endif /* WHATEVER_HPP */
