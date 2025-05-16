/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:17:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/16 15:54:27 by fruan-ba         ###   ########.fr       */
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

std::string	ScalarConverter::isInt(const std::string target) const
{
	long	index;

	index = 0;
	if (target[index] == '-' || target[index] == '+')
		index++;
	while (target[index] >= '0' && target[index] <= '9')
		index++;
	if (target[index] == '\0')
		return ("int: " + target);
	return ("int: impossible");
}

std::string	ScalarConverter::isChar(const std::string target) const
{
	if (target[0] && target[1])
	{
		if (target[0] < 32 || target[0] > 126)
			return ("char: Non displayable");
		else if (target[0] == '\\')
			return ("char: Non displayable");
		else
			return ("char: impossible");
	}
	if (target[0] >= 32 && target[0] <= 126)
		return("char: \'" + target + "\'");
	return ("char: Non displayable");
}

std::string	ScalarConverter::isFloat(const std::string target) const
{
	bool	result;

	result = false;
	if (result == false)
		return ("float: impossible");
	return ("float: tudo ok");
}

std::string	ScalarConverter::isDouble(const std::string target) const
{
	bool	result;

	result = false;
	if (result == false)
		return ("double: impossible");
	return ("double: tudo ok");
}

std::ostream&	operator<<(std::ostream &out, const ScalarConverter &another)
{
	out << "ScalarConverter v1.0 =D" << std::endl;
	return (out);
}
