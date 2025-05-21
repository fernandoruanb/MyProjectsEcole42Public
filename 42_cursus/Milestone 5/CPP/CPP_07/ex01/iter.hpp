/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:51:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 19:52:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T const *a, size_t length, void (*f)(T const &))
{
	std::size_t	index;

	if (!a || length == 0)
		return ;
	index = 0;
	while (index < length)
	{
		f(a[index]);
		index++;
	}
}

#endif /* ITER_HPP */
