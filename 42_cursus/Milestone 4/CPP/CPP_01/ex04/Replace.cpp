/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:09:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 17:18:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace() {}

Replace::~Replace() {}

void	Replace::replace(std::string input, std::string s1, std::string s2)
{
	std::ifstream file(input);
	if (!file.is_open() && file.peek() == EOF)
	{
		std::cout << "You need to have a valid file, please!" << std::endl;
		std::cout << "A valid file needs to exist and to have some content" << std::endl;
		return ;
	}
	std::ofstream out("output.txt");
	if (!out.is_open())
	{
		std::cout << "Unfortunately, happened an error creating the output file" << std::endl;
		return ;
	}

}
