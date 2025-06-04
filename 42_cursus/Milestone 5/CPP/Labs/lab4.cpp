/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab4.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:04:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/01 16:57:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

static bool	is_all_number(const std::string date)
{
	long long	index;

	index = 0;
	while (date[index] != '\0')
	{
		if (date[index] >= '0' && date[index] <= '9')
			index++;
		else
			break ;
	}
	if (date[index] != '\0')
		return (0);
	return (1);
}

static bool	all_right(const std::string date)
{
	std::string	year;
	std::string	month;
	std::string	day;
	size_t	checker;

	year = date.substr(0, 4);
	month = date.substr(5, 2);
	day = date.substr(8, 2);
	if (!is_all_number(year) || !is_all_number(month) || !is_all_number(day))
	{
		std::cerr << "Invalid date format" << std::endl;
		return (0);
	}
	std::stringstream ss(year);
	ss >> checker;
	if (checker < 0)
	{
		std::cerr << "Invalid year format" << std::endl;
		return (0);
	}
	ss.clear();
	ss.str(month);
	ss >> checker;
	if (checker < 0 || checker > 12)
	{
		std::cerr << "Invalid month format" << std::endl;
		return (0);
	}
	ss.clear();
	ss.str(day);
	ss >> checker;
	if (checker < 0 || checker > 30)
	{
		std::cerr << "Invalid day format" << std::endl;
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	std::string	line;
	std::string	date;
	std::string	value;
	std::string	year;
	std::string	month;
	std::string	day;
	std::map<std::string,double> btc;
	size_t	checker;
	size_t	pipe;

	if (argc != 2)
		return (1);
	std::ifstream file(argv[1]);
	if (file.is_open())
	{
		std::getline(file, line);
		while (std::getline(file, line))
		{
			pipe = line.find(" | ");
			if (pipe != std::string::npos)
			{
				date = line.substr(0, pipe);
				if (date.length() != 10 || date[4] != '-' || date[7] != '-')
				{
					std::cerr << "Invalid format date" << std::endl;
					return (1);
				}
				value = line.substr(pipe + 3);
				std::stringstream ss(value);
				ss >> checker;
				if (checker < 0 || checker > 1000)
				{
					std::cerr << "Invalid btc value" << std::endl;
					return (1);
				}
				if (all_right(date))
				{
					btc[date] = checker;
				}
				else
					return (1);
			}
		}
		file.close();
		std::map<std::string,double>::const_iterator it = btc.begin();
		while (it != btc.end())
		{
			std::cout << it->first << " | " << it->second << std::endl;
			++it;
		}
	}
	return (0);
}
