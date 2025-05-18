/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:53:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/17 21:02:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &another)
{
	(void)another;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &another)
{
	(void)another;
	return (*this);
}

bool	ScalarConverter::isPseudo(const std::string &target)
{
	int	index;

	static const std::string	pseudo_list[6] = {
		"nan", "nanf",
		"+inf", "-inf",
		"+inff", "-inff"
	};
	index = 0;
	while (index < 6)
	{
		if (target == pseudo_list[index])
			return (true);
		index++;
	}
	return (false);
}

/*bool	ScalarConverter::isInt(const std::string &target)
{
	long	index;
	long	number;

	index = 0;
	if (target[0] == '-' || target[1] == '+')
	{
		if (target.size() == 1)
			return (false);
		index++;
	}
	while ((unsigned long)index < target.size())
	{
		if (target[index] >= '0' && target[index] <= '9')
			index++;
		if (index > 11)
			break ;
	}
	if ((unsigned long)index == target.size())
	{
		number = static_cast<int>(target);
		if (number > INT_MAX || number < INT_MIN)
			return (false);
		return (true);
	}
	return (false);
}*/

void	ScalarConverter::converter(const std::string &target)
{
	if (isPseudo(target))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (target != "nanf" && target != "+inff" && target != "-inff")
		{
			std::cout << "float: " + target + "f" << std::endl;
			std::cout << "double: " + target << std::endl;
		}
		else
		{
			std::cout << "float: " + target << std::endl;
			std::cout << "double: " + target.substr(0, target.size() - 1) << std::endl;
		}
		return ;
	}
	else if (isChar(target))
	{
		if (target[0] > 32 && target[0] < 127)
		{
			std::cout << "char: " + target << std::endl;
			std::cout << "int: " << std::fixed << static_cast<int>(target[0]) << std::setprecision(1) << std::endl;
			std::cout << "float: " << std::fixed << static_cast<float>(target[0])
				<< std::setprecision(1) << "f" << std::endl;
			std::cout << "double: " << std::fixed << static_cast<double>(target[0])
				<< std::setprecision(1) << std::endl;
		}
		else
		{
			std::cout << "char: non displayable" << std::endl;
			std::cout << "int: " << std::fixed << static_cast<int>(target[0]) << std::endl;
			std::cout << "float: " << std::fixed << static_cast<float>(target[0])
				<< std::setprecision(1) << "f" << std::endl;
			std::cout << "double: " << std::fixed << static_cast<double>(target[0]) << std::setprecision(1) << std::endl;
		}
	}
}

/*bool	ScalarConverter::isFloat(const std::string &target)
{
	long	index;

	index = 0;
	if (target[0] == '+' || target[0] == '-')
	{
		if (target.size() == 1)
			return (false);
		index++;
	}
}*/

bool	ScalarConverter::isChar(const std::string &target)
{
	if (target.size() != 1)
		return (false);
	return (true);
}

std::ostream& operator<<(std::ostream &out, const ScalarConverter &another)
{
	(void)another;
	out << "There is a converter" << std::endl;
	return (out);
}
