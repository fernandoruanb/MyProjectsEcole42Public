/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:32:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/05 16:28:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


static int	check_index(std::string command)
{
	long	checker;

	if (command.empty())
		return (0);
	checker = 0;
	while (command[checker] != '\0')
	{
		if (command[checker] < '0' || command[checker] > '9')
			return (0);
		checker++;
	}
	return (1);
}

int	main(void)
{
	std::string	command;
	PhoneBook	MyPhoneBook;

	while (1)
	{
		std::cout << std::endl;
		std::cout << "ADD -> add a new contact" << std::endl;
		std::cout << "SEARCH -> search a contact or show all contacts" << std::endl;
		std::cout << "EXIT -> exit the PhoneBook program" << std::endl << std::endl;
		std::cout << "<<phonebook>>$ ";
		if (!std::getline(std::cin, command) || command.empty())
		{
			std::cin.clear();
			clearerr(stdin);
		}
		if (command == "ADD")
			MyPhoneBook.add_new_contact();
		else if (command == "SEARCH")
		{
			std::cout << "You need a specif contact (YES/NO)? ";
			std::getline(std::cin, command);
			if (command == "YES" || command == "yes")
			{
				std::cout << std::endl;
				std::cout << "Set the index of the contact: ";
				std::getline(std::cin, command);
				if (check_index(command))
					MyPhoneBook.show_specif_contact(std::stoi(command) - 1);
				else
				{
					std::cout << std::endl;
					std::cout << "Invalid index" << std::endl;
				}
			}
			else if (command == "NO" || command == "no")
				MyPhoneBook.show_all_contacts();
		}
		else if (command == "EXIT")
			break ;
		std::cout << std::endl;
	}
	return (0);
}
