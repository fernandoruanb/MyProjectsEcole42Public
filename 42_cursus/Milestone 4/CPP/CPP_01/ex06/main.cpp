/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:02:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 17:04:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	std::string	level;
	Harl	HarlFilter;

	if (argc != 2)
	{
		std::cerr << "How to use: ./harlFilter [LEVEL_OF_DANGER]" << std::endl;
		std::cerr << "Levels of Danger: DEBUG, INFO, WARNING OR ERROR" << std::endl;
		return (1);
	}
	level = argv[1];
	HarlFilter.complain(level);
	return (0);
}
