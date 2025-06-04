/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab3.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:11:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/31 14:11:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <map>
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	std::string	line;
	std::string	date;
	std::string	value;
	size_t	pipe;
	std::map<std::string,double> btc;
	double	btc_value;

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
				while (date.length() && date[0] == ' ')
					date = date.substr(1);
				value = line.substr(pipe + 3);
				while (value.length() && value[0] == ' ')
					value = value.substr(1);
				std::stringstream ss(value);
				ss >> btc_value;
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
