/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:11:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 13:50:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <iostream>
# include "Pessoa.hpp"
# include <vector>

class List
{
	private:
		std::vector<Person> pessoas;
	public:
		void	add_person(const Person& pessoa);
		void	show_all_people(void) const;
};

#endif /* LIST_HPP */
