/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:25:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/04 16:25:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "List.hpp"
#include "Pessoa.hpp"

Pessoa::Pessoa() {}

Lista::Lista()
{
	index = 0;
	total = 0;
}

void	Lista::show_all_people(void) const
{
	int	num;

	num = 0;
	while (num < total)
	{
		std::cout << std::endl;
		show_specif_person(num);
		num++;
	}
}

int	Lista::show_error_message(std::string message, std::string check) const
{
	int	index;

	if (check.empty())
	{
		std::cout << "You need to fill the camp ";
		std:: cout << message << std::endl;
		std::cin.clear();
		clearerr(stdin);
		return (1);
	}
	if (message == "IDADE")
	{
		index = 0;
		while (check[index] != '\0')
		{
			if (check[index] < '0' || check[index] > '9')
			{
				std::cout << std::endl;
				std::cout << "ONLY NUMBERS!!! " << std::endl;
				std::cout << std::endl;
				return (1);
			}
			index++;
		}
	}
	return (0);
}

void	Lista::add_new_person(void)
{
	Pessoa	new_person;
	std::string	temp;

	std::cout << "Qual é o nome da pessoa? " << std::endl;
	std::cout << "> ";
	std::getline(std::cin, temp);
	if (show_error_message("NOME", temp))
		return ;
	new_person.set_nome(temp);
	std::cout << "Qual é a idade da pessoa? " << std::endl;
	std::cout << "> ";
	std::getline(std::cin, temp);
	if (show_error_message("IDADE", temp))
		return ;
	new_person.set_idade(std::stoi(temp));
	pessoas[index] = new_person;
	index = (index + 1) % 8;
	if (total < 8)
		total++; 
}

void	Lista::show_specif_person(short int target) const
{
	if (target < 0 || target > 7 || total == 0 || target > total)
		return ;
	std::cout << "Index: " << target << std::endl;
	std::cout << "Nome: " << pessoas[target].get_nome() << std::endl;
	std::cout << "Idade: " << pessoas[target].get_idade() << std::endl;
}
