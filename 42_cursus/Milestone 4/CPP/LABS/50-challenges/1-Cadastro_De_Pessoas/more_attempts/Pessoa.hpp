/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pessoa.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:59:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/04 15:59:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PESSOA_HPP
# define PESSOA_HPP

#include <iostream>

class Pessoa
{
	private:
		std::string	nome;
		short int	idade;
	public:
		Pessoa();
		void		set_nome(const std::string &nome);
		void		set_idade(const short int &idade);
		std::string	get_nome(void) const;
		short int	get_idade(void)	const;
};

#endif /* PESSOA_HPP */
