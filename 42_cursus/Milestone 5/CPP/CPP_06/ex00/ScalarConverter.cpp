/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:17:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/16 20:22:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called for ScalarConverter" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Default constructor called for ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &another)
{
	(void)another;
	std::cout << "Copy construcor called" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &another)
{
	(void)another;
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const ScalarConverter &another)
{
	out << "ScalarConverter v1.0 =D" << std::endl;
	return (out);
}
