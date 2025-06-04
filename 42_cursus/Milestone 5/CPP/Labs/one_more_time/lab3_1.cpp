/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab3_1.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:37:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/06/01 14:53:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	std::string	line;
	std::string	date;
	std::string	value;
	size_t	pipe;
	double	new_value;
	std::map<std::string,double>	btc;

	if (argc != 2)
		return (1);
	std::ifstream file(argv[1]);
	if (file.is_open())
	{
		std::getline(file, line);
		while (getline(file, line))
		{
			pipe = line.find(" | ");
			if (pipe != std::string::npos)
			{
				date = line.substr(0, pipe);
				value = line.substr(pipe + 3);
				std::stringstream ss(value);
				ss >> new_value;
				btc[date] = new_value;
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
