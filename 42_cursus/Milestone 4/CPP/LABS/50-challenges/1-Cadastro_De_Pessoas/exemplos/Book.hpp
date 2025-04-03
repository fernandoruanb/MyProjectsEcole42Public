/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Book.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:51:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 14:18:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOK_HPP
# define BOOK_HPP

# include <iostream>

class Book
{
	private:
		std::string	title;
		std::string	author;
	public:
		Book(std::string t, std::string a);
		std::string	get_title(void) const;
		std::string	get_author(void) const;
};

# endif /* BOOK_HPP */
