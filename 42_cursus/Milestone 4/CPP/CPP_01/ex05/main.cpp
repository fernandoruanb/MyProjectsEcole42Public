/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:51:19 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 15:53:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	myDearHarl;
	std::string	level;

	if (argc != 2)
	{
		std::cerr << "How to use: ./harl [filter]" << std::endl;
		std::cerr << "Filters: DEBUG, INFO, WARNING and ERROR" << std::endl;
		return (1);
	}
	level = argv[1];
	myDearHarl.complain(level);
	return (0);
}
