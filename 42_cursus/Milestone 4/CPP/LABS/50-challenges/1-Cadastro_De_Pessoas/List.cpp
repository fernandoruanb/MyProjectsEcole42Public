/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:26:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 13:49:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include "Pessoa.hpp"

void	List::add_person(const Person& pessoa)
{
	pessoas.push_back(pessoa);
}

void	List::show_all_people(void) const
{
	int	index;

	index = 0;
	while (index < pessoas.size())
	{
		std::cout << pessoas[index].get_name() << std::endl;
		std::cout << pessoas[index].get_age() << std::endl;
		std::cout << std::endl;
		index++;
	}
}
