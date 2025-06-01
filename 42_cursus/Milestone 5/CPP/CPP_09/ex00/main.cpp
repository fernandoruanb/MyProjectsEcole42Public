/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:36:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/01 18:53:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	start_check_input(const std::string file)
{
	std::ifstream input(file);

	if (file.is_open())
	{
		if (!start_mount(input))
		{
			file.close();
			return (0);
		}
		file.close();
	}
	else
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Error: You must send an argument and only one" << std::endl;
		return (1);
	}

	std::ifstream db("data.csv");
	std::string	line;
	std::string	date;
	std::string	value;
	std::map<std::string,double> btc;
	double	btc_value;
	size_t	comma;

	if (db.is_open())
	{
		std::getline(db, line);
		while (std::getline(db, line))
		{
			comma = line.find(',');
			if (comma != std::string::npos)
			{
				date = line.substr(0, comma);
				value = line.substr(comma + 1);
				std::stringstream ss(value);
				ss >> btc_value;
				btc[date] = btc_value;
			}
		}
		db.close();
		if (!start_check_input(argv[1])
			return (1);
		/*std::map<std::string,double>::const_iterator it = btc.begin();
		while (it != btc.end())
		{
			std::cout << it->first << ", " << it->second << std::endl;
			++it;
		}*/
	}
	else
	{
		std::cerr << "Error: data.csv could not be read" << std::endl;
		return (1);
	}
	return (0);
}
