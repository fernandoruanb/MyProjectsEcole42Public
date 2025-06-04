/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:37:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/31 13:37:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <sstream>
#include <map>
#include <fstream>
#include <iostream>

int	main(void)
{
	size_t	comma;
	std::string	line;
	std::map<std::string,double> btc;
	std::string	date;
	std::string	value;
	double	new_value;

	std::ifstream file("data.csv");
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
				ss >> new_value;
				btc[date] = new_value;
			}
		}
		file.close();
		std::map<std::string,double>::const_iterator it = btc.begin();
		while (it != btc.end())
		{
			std::cout << it->first << ", " << it->second << std::endl;
			++it;
		}
	}
	return (0);
}
