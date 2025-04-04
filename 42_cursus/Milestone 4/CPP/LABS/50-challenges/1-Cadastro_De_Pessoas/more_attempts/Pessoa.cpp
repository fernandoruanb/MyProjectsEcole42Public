/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pessoa.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:09:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/04 16:09:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pessoa.hpp"

void	Pessoa::set_nome(const std::string &nome)
{
	this->nome = nome;
}

void	Pessoa::set_idade(const short int &idade)
{
	this->idade = idade;
}

std::string	Pessoa::get_nome(void) const
{
	return (nome);
}

short int	Pessoa::get_idade(void) const
{
	return (idade);
}
