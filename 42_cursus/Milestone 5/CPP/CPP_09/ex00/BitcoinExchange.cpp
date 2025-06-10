/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:57:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/10 12:34:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool     checkValidStr(const std::string value)
{
	const char	*ptr = value.c_str();
	bool	flag;

	if (value.empty())
		return (0);
	flag = 0;
        while (*ptr)
        {
                if ((*ptr >= '0' && *ptr <= '9') || *ptr == '.')
		{
			if (*ptr == '.' && flag == 0)
				return (0);
			if (flag == 0)
				flag = 1;
                        ++ptr;
		}
                else
                        return (0);
        }
        return (1);
}

static bool	investigate_date(const std::string date)
{
	std::string	year;
	std::string	month;
	std::string	day;
	ssize_t	checker;
	ssize_t	year_value;
	ssize_t	day_value;
	ssize_t month_value;

	year = date.substr(0, 4);
	month = date.substr(5, 2);
	day = date.substr(8, 2);
	std::stringstream ss(year);
	ss >> checker;
	if (checker < 0)
	{
		std::cerr << RED "Error: bad input => " << BRIGHT_YELLOW << date << RESET << std::endl;
		return (0);
	}
	year_value = checker;
	ss.clear();
	ss.str(month);
	ss >> checker;
	month_value = checker;
	if (checker <= 0 || checker > 12)
	{
		std::cerr << RED "Error: bad input => " << BRIGHT_YELLOW << date << RESET << std::endl;
		return (0);
	}
	ss.clear();
	ss.str(day);
	ss >> checker;
	if (checker <= 0 || checker > 31)
	{
		std::cerr << RED "Error: bad input => " << BRIGHT_YELLOW << date << RESET << std::endl;
		return (0);
	}
	day_value = checker;
	if (month_value == 2 && day_value > 28)
	{
		if (year_value % 4 == 0 && (year_value % 100 != 0 || year_value % 400 == 0))
		{
			if (day_value > 0 && day_value <= 29)
				return (1);
		}
		std::cerr << RED "Error: bad input => " << BRIGHT_YELLOW << date << RESET << std::endl;
		return (0);
	}
	return (1);
}

static void	print_result(const std::string date, std::map<std::string,double> input, std::map<std::string,double> db)
{
	std::map<std::string,double>::const_iterator it = db.lower_bound(date);
	double	btc_value;
	double	base;

	if (db.empty())
	{
		std::cerr << RED "Error: database is empty!" RESET << std::endl;
		return ;
	}
	btc_value = input[date];
	if (it == db.end())
		--it;
	while (it->first > date)
	{
		if (it == db.begin())
		{
			std::cerr << RED "Error: there are not dates availables to calculate the answer" RESET << std::endl;
			return ;
		}
		--it;
	}
	base = it->second;
	if (it != db.end() && it != db.begin())
		std::cout << BRIGHT_GREEN << date << ORANGE " => " << LIGHT_BLUE << btc_value << ORANGE " = " << BRIGHT_YELLOW << btc_value * base << RESET << std::endl;
}

void	start_mount(std::ifstream &file, std::map<std::string,double> db)
{
	std::map<std::string,double> inputDb;
	std::string	line;
	std::string	value;
	std::string	date;
	double	btc_value;
	size_t	pipe;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		pipe = line.find(" | ");
		if (pipe != std::string::npos)
		{
			date = line.substr(0, pipe);
			if (date.length() != 10 || date[4] != '-' || date[7] != '-')
			{
				std::cerr << RED "Error: bad input => " << BRIGHT_YELLOW << date << RESET << std::endl;
				continue ;
			}
			value = line.substr(pipe + 3);
			if (!checkValidStr(value))
			{
				std::cerr << RED "Error: invalid value of bitcoin!!!" RESET << std::endl;
				continue ;
			}
			std::stringstream ss(value);
			ss >> btc_value;
			if (btc_value < 0)
			{
				std::cerr << RED "Error: not a positive number." RESET << std::endl;
				continue ;
			}
			if (btc_value > 1000)
			{
				std::cerr << RED "Error: too large a number." RESET << std::endl;
				continue ;
			}
			if (!investigate_date(date))
				continue ;
			inputDb[date] = btc_value;
			print_result(date, inputDb, db);
		}
		else
			std::cerr << RED "Error: bad input => " << BRIGHT_YELLOW << line << RESET << std::endl;
	}
	file.close();
}
