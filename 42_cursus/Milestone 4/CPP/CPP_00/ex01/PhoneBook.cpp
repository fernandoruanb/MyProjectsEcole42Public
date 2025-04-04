/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:46:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 20:56:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	total = 0;
}

bool	PhoneBook::show_add_error(const std::string message, std::string temp) const
{
	int	index;

	if (temp.empty())
        {
		std::cout << std::endl;
                std::cout << "You need to fill the camp ";
		std::cout << message << std::endl;
		return (1);
        }
	if (message == "PHONE NUMBER")
	{
		index = 0;
		while (temp[index] != '\0')
		{
			if (temp[index] >= '0' && temp[index] <= '9')
				index++;
			else
			{
				std::cout << std::endl;
				std::cout << "ONLY NUMBERS!!!" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

void	PhoneBook::add_new_contact(void)
{
	Contact	new_contact;
	std::string	temp;

	std::cout << "What is the First Name? ";
	std::getline(std::cin, temp);
	if (show_add_error("FIRST NAME", temp))
		return ;
	new_contact.set_first_name(temp);
	std::cout << std::endl;

	std::cout << "What is the Last Name? ";
	std::getline(std::cin, temp);
	if (show_add_error("LAST NAME", temp))
                return ;
	new_contact.set_last_name(temp);
	std::cout << std::endl;

	std::cout << "What is the Nickname? ";
	std::getline(std::cin, temp);
	if (show_add_error("NICKNAME", temp))
                return ;
	new_contact.set_nickname(temp);
	std::cout << std::endl;

	std::cout << "What is your Phone Number? ";
	std::getline(std::cin, temp);
	if (show_add_error("PHONE NUMBER", temp))
                return ;
	new_contact.set_phone_number(temp);
	std::cout << std::endl;

	std::cout << "What is the Darkest Secret? ";
	std::getline(std::cin, temp);
	if (show_add_error("DARKEST SECRET", temp))
                return ;
	new_contact.set_darkest_secret(temp);
	std::cout << std::endl;

	phonebook[index % 8] = new_contact;
	index = (index + 1) % 8;
	if (total < 8)
		total++;
}

void	PhoneBook::show_all_contacts(void) const
{
	int	num;

	num = 0;
	while (num < total)
	{
		show_specif_contact(num);
		num++;
	}
}

void	PhoneBook::show_specif_contact(int index) const
{
	if (index < 0 || index > 7)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (index > total)
	{
		std::cout << "The index surpass the total of contacts" << std::endl;
		return ;
	}
	if (total == 0)
	{
		std::cout << "Doesn't exist a contact" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "Index: " << index + 1 << std::endl; 
	std::cout << "First Name: ";
	std::cout << phonebook[index].get_first_name() << std::endl;
	std::cout << "Last Name: ";
	std::cout << phonebook[index].get_last_name() << std::endl;
	std::cout << "Nickname: ";
	std::cout << phonebook[index].get_nickname() << std::endl;
	std::cout << "Phone Number: ";
	std::cout << phonebook[index].get_phone_number() << std::endl;
}
