/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:24:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 13:43:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pessoa.hpp"
#include "List.hpp"

int	main(void)
{
	Person	MyFirstPerson("Fernando", 23);
	Person	MySecondPerson("Felipe", 35);
	List	MyList;

	MyList.add_person(MyFirstPerson);
	MyList.add_person(MySecondPerson);
	MyList.show_all_people();
	return (0);
}
