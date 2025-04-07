/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:59:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 17:19:24 by fruan-ba         ###   ########.fr       */
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
	Replace	MyReplace;

	if (argc != 4)
		return (1);
	input = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	MyReplace.replace(input, s1, s2);
	return (0);
}
