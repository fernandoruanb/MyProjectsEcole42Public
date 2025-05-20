/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:53:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/20 14:51:11 by fruan-ba         ###   ########.fr       */
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

bool	ScalarConverter::isInt(const std::string &target)
{
	int	index;
	double	number;

	errno = 0;
	index = 0;
	number = std::strtol(target.c_str(), NULL, 10);
	if (errno == ERANGE)
		return (false);
	if (target[0] == '.')
		return (0);
	if (target[0] == '-' || target[0] == '+')
	{
		if (target.size() == 1 || target[1] == '.')
			return (false);
		index++;
	}
	while ((unsigned long)index < target.size())
	{
		if (target[index] >= '0' && target[index] <= '9')
		       index++;
		else
			return (false) ;
	}
	return (true);
}

void	ScalarConverter::converter(const std::string &target)
{
	double	number;

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
		if (target[0] > 31 && target[0] < 127)
		{
			std::cout << "char: " << "\'" << target << "\'" << std::endl;
			std::cout << "int: " << std::fixed << std::setprecision(1) 
				<< static_cast<int>(target[0]) << std::setprecision(1) << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) 
				<< static_cast<float>(target[0]) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1)
				<< static_cast<double>(target[0]) << std::endl;
		}
		else
		{
			if (target[0] < -128 || target[0] > 126)
				std::cout << "char: impossible" << std::endl;
			else
				std::cout << "char: non displayable" << std::endl;
			std::cout << "int: " << std::fixed << static_cast<int>(target[0]) << std::endl;
			std::cout << "float: " << std::fixed << static_cast<float>(target[0])
				<< std::setprecision(1) << "f" << std::endl;
			std::cout << "double: " << std::fixed << static_cast<double>(target[0])
				<< std::setprecision(1) << std::endl;
		}
	}
	else if (isInt(target))
	{
		number = std::atof(target.c_str());
		if (static_cast<int>(number) < 0 || static_cast<int>(number) > 127)
                        std::cout << "char: impossible" << std::endl;
                else if (static_cast<int>(number) < 32 || static_cast<int>(number) > 126)
                        std::cout << "char: Non displayable" << std::endl;
                else
                        std::cout << "char: " << "\'" << static_cast<char>(number) << "\'" << std::endl;
		if (number > INT_MAX || number < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << std::atoi(target.c_str()) << std::endl;
		if (number > FLT_MAX || number < -FLT_MAX)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(1) << std::atof(target.c_str()) << "f" << std::endl;
		if (number > DBL_MAX || number < -DBL_MAX)
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << std::atof(target.c_str()) << std::endl;
	}
	else if (isFloat(target))
	{
		number = std::atof(target.c_str());
		if (static_cast<int>(number) < 0 || static_cast<int>(number) > 127)
			std::cout << "char: impossible" << std::endl;
		else if (static_cast<int>(number) < 32 || static_cast<int>(number) > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << "\'" << static_cast<char>(number) << "\'" << std::endl;
		if (number > INT_MAX || number < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(number) << std::endl;
		if (number > FLT_MAX || number < -FLT_MAX)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;
		if (number > DBL_MAX || number < -DBL_MAX)
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl;
	}
	else if (isDouble(target))
	{

		number = std::strtof(target.c_str(), NULL);
		if (number < 0 || number > 127)
			std::cout << "char: impossible" << std::endl;
		else if (number < 32 || number > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << "\'" << static_cast<char>(number) << "\'" << std::endl;
		if (number > INT_MAX || number < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(number) << std::endl;
		if (number > FLT_MAX || number < -FLT_MAX)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;
		if (number > DBL_MAX || number < -DBL_MAX)
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl;	
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

bool	ScalarConverter::isDouble(const std::string &target)
{
	long long	index;
	double	number;

	errno = 0;
	number = std::strtod(target.c_str(), NULL);
	if (errno == ERANGE)
		return (false);
	index = 0;
	if (target[0] == '.')
		return (false);
	if (target[0] == '+' || target[0] == '-')
	{
		if (target.size() == 1 || target[1] == '.')
			return (false);
		index++;
	}
	while ((unsigned long)index < target.size())
	{
		if (target[index] >= '0' && target[index] <= '9')
			index++;
		else
			break ;
	}
	if (target[index] != '.' && target[index] != '\0')
		return (false);
	if (target[index] == '.' && target[index + 1] == '\0')
		return (false);
	index++;
	while ((unsigned long)index < target.size())
	{
		if (target[index] >= '0' && target[index] <= '9')
			index++;
		else
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &target)
{
	long long	index;
	int	count;
	float	number;
	
	errno = 0;
	index = 0;
	count = 0;
	number = std::strtof(target.c_str(), 0);
	if (errno == ERANGE)
		return (false);
	while ((unsigned long)index < target.size())
	{
		if (target[index] == 'f')
			count++;
		if (count > 1)
			return (false);
		index++;
	}
	index = 0;
	if (target[0] == '.')
		return (false);
	if (target[0] == '+' || target[0] == '-')
	{
		if (target.size() == 1 || target[1] == '.' || target[1] == 'f')
			return (false);
		index++;
	}
	if (target[target.size() - 1] != 'f')
		return (false);
	while ((unsigned long)index < target.size())
	{
		if (target[index] >= '0' && target[index] <= '9')
			index++;
		else
			break ;
	}
	if (target[index] != '.' && target[index] != 'f')
		return (false);
	if (target[index] == '.' && target[index + 1] == '\0')
		return (false);
	else if (target[index] == 'f')
		return (true);
	else
	{
		index++;
		if (target[index] < '0' || target[index] > '9')
			return (false);
		while ((unsigned long)index < target.size() && target[index] != 'f')
		{
			if (target[index] >= '0' && target[index] <= '9')
				index++;
			else
				return (false);
		}
	}
	if (target[index] != 'f')
		return (false);
	return (true);
}

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
