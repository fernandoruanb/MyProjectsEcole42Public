/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:03:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/04 16:03:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIST_HPP
# define LIST_HPP

# include "Pessoa.hpp"
# include <iostream>

class	Lista
{
	private:
		Pessoa	pessoas[8];
		int	index;
		int	total;
	public:
		Lista();
		void	show_all_people(void) const;
		void	add_new_person(void);
		void	show_specif_person(short int index) const;
		int	show_error_message(std::string message, std::string check) const;
};

#endif /* LIST_HPP */
