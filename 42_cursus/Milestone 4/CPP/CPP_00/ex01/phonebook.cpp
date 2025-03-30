/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:17:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/30 18:26:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"
using namespace std;

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

static void	call_search(t_phonebook *phone, int stored)
{
	int	index;

	index = 0;
	while (index < stored)
	{
		cout << "Index: " << index + 1 << endl;
		cout << "Firstname: " << phone[index].first_name << endl;
		cout << "Nickname: " << phone[index].nickname << endl;
		cout << "Phone Number: " << phone[index].phone_number << endl;
		cout << "Darkest Secret: " << phone[index].darkest_secret << endl;
		index++;
		cout << endl;
	}
}

static int	check_digits(t_phonebook *phone, int index)
{
	int	num;

	num = 0;
	while (phone[index].phone_number[num] != '\0')
	{
		if (phone[index].phone_number[num] < '0' ||
		phone[index].phone_number[num] > '9')
			return (0);
		num++;
	}
	return (1);
}

static void	call_add(t_phonebook *phone, int index, int *stored)
{
	cout << GREEN << "You can type one by one information or all in one =D" << RESET << endl;
	cout << YELLOW << "Firstname | Nickname | Phone_Number | Darkest Secret" << RESET << endl;
	cout << RED << "If one information is wrong, you will need to continue by that point" RESET << endl << endl;
	cout << GREEN << "What is the firstname: " << RESET;
	cin.ignore();
	cin >> phone[index].first_name;
	cout << endl;
	cout << YELLOW << "What is the nickname? " << RESET;
	cin.ignore();
	cin >> phone[index].nickname;
	cout << endl;
	cout << BWHITE << "What is the phone number? " << RESET;
	cin.ignore();
	cin >> phone[index].phone_number;
	cout << endl;
	while (!check_digits(phone, index))
	{
		cout << RED << "ONLY NUMBERS!!!" << RESET << endl;
		cout << BWHITE << "What is the phone number, AGAIN? " << RESET;
        	cin >> phone[index].phone_number;
	}
	cout << RED << "What is the darkest secret? " << RESET;
	cin >> phone[index].darkest_secret;
	cout << endl;
	(*stored)++;
}

static void	show_intro_message(void)
{
	cout << "________________________________" << endl;
	cout << "|" << "      " << "                	       |" << endl;
	cout << "|" << "      " << "               	       |" << endl;
	cout << "|" << "      " << "                        |" << endl;
	cout << "|" << "     PhoneBook(v1.0) =D" << "       |" << endl;
	cout << "|" << "     ___fruan-ba 42SP___" << "      |" << endl;
	cout << "|" << "      " << "                	       |" << endl;
	cout << "|" << "      " << "               	       |" << endl;
	cout << "|______________________________|" << endl << endl;
	cout << GREEN << "------PHONEBOOK PROGRAM v1.0------" << RESET << endl;
	cout << YELLOW << "ADD - you can add new contacts with this option" << RESET << endl;
	cout << BBLUE << "SEARCH - you can search the stored contacts" << RESET << endl;
	cout << RED << "EXIT - if you need exit the phonebook program" << RESET << endl;
	cout << GREEN << "----------------------------------" << RESET << endl;
}

int	main(void)
{
	t_phonebook	phone[8];
	char	cmd[50];
	static int	index = 0;
	static int	stored = 0;

	while (1)
	{
		show_intro_message();
		cout << BWHITE << "phonebook>>$ " << RESET;
		cin >> cmd;
		cout << endl;
		if (index > 8)
			index %= 8;
		if (stored > 8)
			stored = 8;
		if (ft_strcmp(cmd, "ADD") == 0)
			call_add(phone, index++, &stored);
		else if (ft_strcmp(cmd, "SEARCH") == 0)
			call_search(phone, stored);
		else if (ft_strcmp(cmd, "EXIT") == 0)
			break ;
		else
			cout << RED << "Invalid option. Please try again" << RESET << endl << endl;
	}
	cout << GREEN << "Thank you very much to use PhoneBook v1.0 =D" << RESET << endl;
	return (0);
}
