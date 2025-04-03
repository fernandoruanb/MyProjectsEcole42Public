/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BookShelf.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:55:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 13:59:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOKSHELF_HPP
# define BOOKSHELF_HPP

# include "Book.hpp"
# include <vector>

class	BookShelf
{
	private:
		std::vector<Book> books;
	public:
		void	add_new_book(const Book& book);
		void	show_all_books(void);
};

#endif /* BOOKSHELF_HPP */
