/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:32:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/21 11:42:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


static int	ft_atoi(std::string command)
{
	int	index;
	long	result;
	int	signal;

	index = 0;
	result = 0;
	signal = 1;
	while (command[index] == ' ' || command[index] == '\t' || command[index] == '\f'
		|| command[index] == '\v' || command[index] == '\r')
		index++;
	if (command[index] == '+' || command[index] == '-')
	{
		if (command[index] == '-')
			signal *= -1;
		index++;
	}
	while (command[index] >= '0' && command[index] <= '9')
	{
		result *= 10;
		result += command[index] - '0';
		index++;
	}
	if (result < 0 || result > 8)
		return (-1);
	return ((int)result);
}

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
	std::string	cmd;
	int	index;
	PhoneBook	MyPhoneBook;

	while (1)
	{
		std::cout << std::endl;
		std::cout << std::setfill('-') << std::setw(55) << "-" << std::endl;
		std::cout << "| 1.ADD -> add a new contact =D" << std::endl;
		std::cout << "| 2.SEARCH -> search a contact or show all contacts :)" << std::endl;
		std::cout << "| 3.EXIT -> exit the PhoneBook program D=" << std::endl;
		std::cout << "| TOTAL_CONTACTS(" << MyPhoneBook.get_total() << "/8)" << " ;)" << std::endl;
		std::cout << std::setfill('-') << std::setw(55) << "-" << std::endl << std::endl;
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
			MyPhoneBook.show_all_contacts();
			std::cout << "You need a specif contact (YES/NO)? ";
			std::getline(std::cin, cmd);
			if (cmd == "YES" || cmd == "yes")
			{
				std::cout << std::endl;
				std::cout << "Set the index of the contact: ";
				std::getline(std::cin, cmd);
				if (check_index(cmd))
				{
					index = ft_atoi(cmd) - 1;
					MyPhoneBook.show_specif_contact(index);
				}
				else
				{
					std::cout << std::endl;
					std::cerr << "The index needs to be a number, please!";
				}
			}
			else if (cmd == "NO" || cmd == "no")
				MyPhoneBook.show_all_contacts();
		}
		else if (command == "EXIT")
			break ;
		if (command != "ADD" && command != "EXIT" && command != "SEARCH")
		{
			std::cerr << std::endl;
			std::cerr << "Invalid input. You need to choose a valid command!!!";
		}
		std::cout << std::endl;
		std::cin.clear();
		clearerr(stdin);
	}
	return (0);
}
