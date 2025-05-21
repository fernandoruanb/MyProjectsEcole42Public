/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:27:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 11:48:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARITHMETIC_HPP
# define ARITHMETIC_HPP

# include <iostream>
# include <stdexcept>

template<typename T>
T add(const T& a, const T& b)
{
	return (a + b);
}
template<typename SUB>
SUB sub(const SUB& a, const SUB& b)
{
	return (a - b);
}
template<typename T>
T mul(const T& a, const T& b)
{
	return (a * b);
}
template<typename DIV>
DIV my_div(const DIV& a, const DIV& b)
{
	try
	{
		if (b == 0)
			throw (std::domain_error("Division by Zero Error"));
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	return (a / b);
}
template<typename MOD>
MOD mod(const MOD& a, const MOD& b)
{
	return (a % b);
}

#endif /* ARITHMETIC_HPP */
