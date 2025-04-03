/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:59:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/03 14:19:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Book.hpp"

Book:: Book(std::string n, std::string a)
{
	title = n;
	author = a;
}

std::string	Book::get_title(void) const
{
	return (title);
}

std::string	Book::get_author(void) const
{
	return (author);
}
