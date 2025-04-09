	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:59:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 23:43:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

static void	make_replace(std::ifstream &file, std::ofstream &out, std::string s1, std::string s2)
{
	std::string	line;
	int	pos;

	while (std::getline(file, line))
	{
		pos = 0;
		while (pos != -1)
		{
			pos = line.find(s1);
			if (pos != -1)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s1.length();
			}
		}
		out << line << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::string	input;
	std::string	output;
	std::string	s1;
	std::string	s2;

	if (argc != 4)
	{
		std::cerr << "How to use: [filename] [string1] [string2]" << std::endl;
		return (1);
	}
	input = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream file(input.c_str());
	if (!file.is_open() || file.peek() == EOF)
	{
		std::cerr << "You need to input a valid file, please" << std::endl;
		return (1);
	}
	output = input + ".replace";
	std::ofstream out(output.c_str());
	if (!out.is_open())
	{
		std::cerr << "Unfortunately, we failed to open the output file" << std::endl;
		file.close();
		return (1);
	}
	make_replace(file, out, s1, s2);
	file.close();
	out.close();
	return (0);
}
