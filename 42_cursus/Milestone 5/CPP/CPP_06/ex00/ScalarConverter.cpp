/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:17:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/16 17:58:34 by fruan-ba         ###   ########.fr       */
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
	long	result;
	long	is_sign;

	index = 0;
	result = 0;
	is_sign = 1;
	if (target[index] == '-' || target[index] == '+')
	{
		if (target[index] == '-')
			is_sign = -1;
		index++;
	}
	while (target[index] >= '0' && target[index] <= '9')
	{
		result *= 10;
		result += target[index] - '0';
		if ((result * is_sign) > INT_MAX || (result * is_sign) < INT_MIN)
			return ("int: impossible");
		index++;
	}
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
