/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:59:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 13:55:23 by fruan-ba         ###   ########.fr       */
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

	if (argc != 4)
		return (1);
	input = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	std::ifstream file(input);
	if (!file.is_open() || file.peek() == EOF)
	{
		std::cout << "The filename needs to be real and with content!!!" << std::endl;
		return (1);
	}
	std::ofstream file_out("output.txt");
	if (!file_out.is_open())
	{
		std::cout << "ERROR opening the output file" << std::endl;
		return (1);
	}
	std::cout << input << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	return (0);
}
