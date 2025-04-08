	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:59:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 11:55:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	main(int argc, char **argv)
{
	std::string	input;
	std::string	output;
	std::string	s1;
	std::string	s2;
	std::string	line;
	int	pos;

	if (argc != 4)
		return (1);
	input = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream file(input);
	if (!file.is_open() || file.peek() == EOF)
	{
		std::cerr << "You need to input a valid file, please" << std::endl;
		return (1);
	}
	output = input + ".replace";
	std::ofstream out(output);
	if (!out.is_open())
	{
		std::cerr << "Unfortunately, we failed to open the output file" << std::endl;
		return (1);
	}
	line = std::getline(std::cin, file);
	std::cout << "achei: " << pos << std::endl;
	file.close();
	out.close();
	return (0);
}
