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

std::string	ScalarConverter::isInt(std::string target) const
{
	int	result;
	int	length;
	std::string new_target;

	length = 0;
	result = 0;
	try
	{
		result = std::stoi(target);
		while (result > 0)
		{
			result /= 10;
			length++;
		}
		if (length == 0)
			length = 1;
		return ("int: " + target.substr(0, length));
	}
	catch (std::exception &exception)
	{
		return ("int: impossible");
	}
}

std::string	ScalarConverter::isChar(std::string target) const
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

std::string	ScalarConverter::isFloat(std::string target) const
{
	long	index;

	index = 0;
	while (target[index] >= '0' && target[index] <= '9')
	{
		if (index > LONG_MAX - 1)
			return ("float: impossible");
		index++;
	}
	if (target[index] == '\0')
		return ("float: " + target + ".0f");
	else if (target[index] == '.')
	{
		++index;
		while (target[index] >= '0' && target[index] <= '9')
		{
			if (index > LONG_MAX - 1)
				return ("float: impossible");
			index++;
		}
		if (target[index] == '\0')
			return ("float: " + target + "f");
	}
	return ("float: impossible");
}

std::string	ScalarConverter::isDouble(std::string target) const
{
	long    index;

        index = 0;
        while (target[index] >= '0' && target[index] <= '9')
        {
                if (index > LONG_MAX - 1)
                        return ("double: impossible");
                index++;
        }
        if (target[index] == '\0')
                return ("double: " + target + ".0");
        else if (target[index] == '.')
        {
                ++index;
                while (target[index] >= '0' && target[index] <= '9')
                {
                        if (index > LONG_MAX - 1)
                                return ("double: impossible");
                        index++;
                }
                if (target[index] == '\0')
                        return ("double: " + target);
        }
        return ("double: impossible");
}

std::ostream&	operator<<(std::ostream &out, const ScalarConverter &another)
{
	out << "ScalarConverter v1.0 =D" << std::endl;
	return (out);
}
