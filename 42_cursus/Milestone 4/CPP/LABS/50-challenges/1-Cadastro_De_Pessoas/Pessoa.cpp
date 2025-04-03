/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pessoa.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:24:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 13:45:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pessoa.hpp"
#include "List.hpp"

Person::Person(std::string name, int age) : name(name), age(age) {}

std::string	Person::get_name(void) const
{
	return (name);
}

int	Person::get_age(void) const
{
	return (age);
}
