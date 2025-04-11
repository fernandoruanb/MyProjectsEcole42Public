/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:42:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/11 20:06:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>
# include <cstdio>
# include <iomanip>

class PhoneBook
{
	private:
		Contact phonebook[8];
		int	index;
		int	total;
		bool	show_add_error(const std::string message, const std::string temp) const;
		void    correct_str(std::string &temp) const;
	public:
		PhoneBook(void);
		void	add_new_contact(void);
		void	show_specif_contact(int index) const;
		void	show_all_contacts(void) const;
		int	get_total(void) const;
};

#endif /* PHONEBOOK_HPP */
