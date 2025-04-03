/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pessoa.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:06:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 13:47:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PESSOA_HPP
# define PESSOA_HPP

# include <iostream>

class Person
{
	private:
		std::string	name;
		int	age;
	public:
		Person(std::string n, int a);
		std::string	get_name(void) const;
		int	get_age(void) const;
};

#endif /* PESSOA_HPP */
