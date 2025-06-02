/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:36:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/02 14:30:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << RED "Error: could not open file." RESET << std::endl;
		return (1);
	}

	std::ifstream db("data.csv");
	std::ifstream inputDb(argv[1]);
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
		if (!inputDb.is_open())
		{
			std::cerr << RED "Error: could not open file" RESET << std::endl;
			return (1);
		}
		else
			start_mount(inputDb, btc);
		/*std::map<std::string,double>::const_iterator it = btc.begin();
		while (it != btc.end())
		{
			std::cout << it->first << ", " << it->second << std::endl;
			++it;
		}*/
	}
	else
	{
		std::cerr << RED "Error: data.csv could not be read" RESET << std::endl;
		return (1);
	}
	return (0);
}
