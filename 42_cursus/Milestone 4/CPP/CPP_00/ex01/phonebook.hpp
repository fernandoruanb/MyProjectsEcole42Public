/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:25:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/30 17:32:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define RESET "\033[0m"
# define BBLUE       "\033[1;34m"
# define BWHITE      "\033[1;37m"
# define BCYAN       "\033[1;36m"

typedef struct s_phonebook
{
	int	index;
	char	first_name[50];
	char	nickname[50];
	char	phone_number[50];
	char	darkest_secret[50];
}	t_phonebook;

#endif /* PHONEBOOK_HPP */
