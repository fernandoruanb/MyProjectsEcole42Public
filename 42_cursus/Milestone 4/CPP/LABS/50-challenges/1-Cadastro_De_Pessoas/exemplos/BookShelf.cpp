/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BookShelf.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:02:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 14:10:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Book.hpp"
#include "BookShelf.hpp"
#include <vector>

void	BookShelf::add_new_book(const Book& book)
{
	books.push_back(book);
}

void	BookShelf::show_all_books(void)
{
	int	index;

	index = 0;
	while (index < books.size())
	{
		std::cout << books[index].get_title() << std::endl;
		std::cout << books[index].get_author() << std::endl;
		std::cout << std::endl;
		index++;
	}
}
