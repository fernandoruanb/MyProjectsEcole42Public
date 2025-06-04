/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:07:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/31 12:07:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <iostream>
#include <fstream>

int main(void)
{
	std::ifstream file("data.csv");
	std::string	line;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			std::cout << line << std::endl;
		}
		file.close();
	}
	return (0);
}
