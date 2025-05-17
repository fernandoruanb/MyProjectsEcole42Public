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

bool	ScalarConverter::isPseudo(const std::string& target)
{
	int	index;

	static const std::string targets[6] = {
		"nan", "nanf",
		"+inf", "-inf",
		"+inff", "-inff"
	};
	index = 0;
	while (index < 6)
	{
		if (targets[index] == target)
			return (true);
		index++;
	}
	return (false); 	
}

bool	ScalarConverter::isChar(const std::string& target)
{
	unsigned char	caracter;

	if (target.size() != 1)
		return (false);
	caracter = static_cast<unsigned char>(target[0]);
	return (std::isprint(caracter);	
}

bool	ScalarConverter::isInt(const std::string& target)
{
	int	index;

	if (target.empty())
		return (false);
	if (target[0] == '-' || target[0] == '+')
	{
		if (target.size() == 1)
			return (false);
	}
	index = 1;
	while (index < target.size())
	{
		if (!std::isdigit(static_cast<unsigned char>(target[index]);
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string& target)
{
	std::string	number;
	int	index;

	if (target.size() < 2)
		return (false);
	if (target.back() != 'f')
		return (false);
	number = target.substr(0, target.size() - 1);
	index = 0;
}

std::ostream&	operator<<(std::ostream &out, const ScalarConverter &another)
{
	out << "ScalarConverter v1.0 =D" << std::endl;
	return (out);
}
