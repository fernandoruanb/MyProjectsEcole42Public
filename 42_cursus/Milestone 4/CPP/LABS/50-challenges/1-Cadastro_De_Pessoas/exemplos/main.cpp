/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:10:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 14:16:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BookShelf.hpp"
#include "Book.hpp"

int	main(void)
{
	Book	MyFirstBook("O alquimista", "Paulo Coelho");
	Book	MySecondBook("O diário de um mago", "Paulo Coelho");
	BookShelf	MyBookShelf;

	MyBookShelf.add_new_book(MyFirstBook);
	MyBookShelf.add_new_book(MySecondBook);
	MyBookShelf.show_all_books();
	return (0);
}
