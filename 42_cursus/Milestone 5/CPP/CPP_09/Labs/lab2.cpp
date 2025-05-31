/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:15:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/31 12:15:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int	main(void)
{
	std::ifstream file("data.csv");
	std::string line;
	std::map<std::string,double> btc;
	std::string date;
	std::string value;
	double btc_value;
	size_t	comma;

	if (file.is_open())
	{
		while (std::getline(file, line))
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
		file.close();
		std::map<std::string,double>::iterator it = btc.begin();
		while (it != btc.end())
		{
			std::cout << it->first << ", " << it->second << std::endl;
			++it;
		}
	}
	return (0);
}
