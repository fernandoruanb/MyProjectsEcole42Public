/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:59:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/04 16:59:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "Pessoa.hpp"
#include "List.hpp"

int	main(void)
{
	std::string	command;
	Lista	MyList;
	int	current_index;

	while (1)
	{
		std::cout << std::endl;
		std::cout << "Do you want to add a contact? (ADD)" << std::endl;
		std::cout << "Do you want to exit the program? (EXIT) or type nothing" << std::endl;
		std::cout << "Do you want to search the contacts? (SEARCH)" << std::endl << std::endl;
		std::cout << ">>$ ";
		std::getline(std::cin, command);
		if (command.empty())
		{
			std::cout << std::endl;
			break ;
		}
		if (command == "ADD" || command == "add")
			MyList.add_new_person();
		if (command == "EXIT" || command == "exit")
		{
			std::cout << std::endl;
			break ;
		}
		if (command == "SEARCH" || command == "search")
		{
			std::cout << "Do you want to see a specif contact (YES/NO)? ";
			std::getline(std::cin, command);
			if (command.empty())
			{
				std::cout << std::endl;
				break ;
			}
			if (command == "YES" || command == "yes")
			{
				std::cout << std::endl;
				std::cout << "What is the index of that contact? ";
				std::getline(std::cin, command);
				if (command.empty())
				{
					std::cout << std::endl;
					break ;
				}
				current_index = std::stoi(command);
				if ((current_index - 1) < 0 || (current_index - 1) > 8)
					continue ;
				else
					MyList.show_specif_person(current_index - 1);
			}
			else if (command == "NO" || command == "no")
				MyList.show_all_people();
		}
	}

	return (0);
}
