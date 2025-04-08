/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:54:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 17:22:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {};

Harl::~Harl(void) {};

void	Harl::debug(void)
{
	std::cout << "That is a debug message." << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "That is an info message." << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "That is the warning message." << std::endl;
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "That is an error message." << std::endl;
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	index;

	void (Harl::*ultimate_decision[4])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	index = 0;
	while (index < 4)
	{
		if (level == levels[index])
		{
			while (index < 4)
			{
				std::cout << std::endl;
				(this->*ultimate_decision[index])();
				index++;
			}
		}
		index++;
	}
	if (index == 4)
	{
		std::cout << "You don't have problems, man =D" << std::endl;
		std::cout << std::endl;
	}
}
