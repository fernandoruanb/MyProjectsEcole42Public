/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab4.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:53:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/01 15:43:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <sstream>
#include <fstream>

static bool	is_all_number(const std::string str)
{
	long long	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= '0' && str[index] <= '9')
			index++;
		else
			break ;
	}
	if (str[index] == '\0')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	std::string	line;
	size_t	pipe;
	double	btc_value;
	std::map<std::string,double>	btc;
	std::string	date;
	std::string	value;
	std::string	year;
	std::string	month;
	std::string	day;
	size_t checker;

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
					std::cerr << "Invalid date format" << std::endl;
					return (1);
				}
				year = line.substr(0, 4);
				month = line.substr(5, 2);
				day = line.substr(8, 2);
				std::stringstream ss(year);
				ss >> checker;
				if (!is_all_number(year) || checker < 0)
				{
					std::cerr << "Invalid year format" << std::endl;
					return (1);
				}
				ss.clear();
				ss.str(month);
				ss >> checker;
				if (!is_all_number(month) || checker < 1 || checker > 12)
				{
					std::cerr << "Invalid month format" << std::endl;
					return (1);
				}
				ss.clear();
				ss.str(day);
				ss >> checker;
				if (!is_all_number(day) || checker < 1 || checker > 30)
				{
					std::cerr << "Invalid day format" << std::endl;
					return (1);
				}
				value = line.substr(pipe + 3);
				ss.clear();
				ss.str(value);
				ss >> btc_value;
				if (btc_value < 0 || btc_value > 1000)
				{
					std::cerr << "Invalid btc format" << std::endl;
					return (1);
				}
				btc[date] = btc_value;
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
