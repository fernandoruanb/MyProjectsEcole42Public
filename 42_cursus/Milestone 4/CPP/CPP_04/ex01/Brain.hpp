/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:08:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 18:57:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string ideas[100];
		unsigned int total;
	public:
		Brain(void);
		~Brain(void);
		Brain(const Brain &other);
		Brain& operator=(const Brain &other);
		void	add_new_idea(void);
		void	get_an_idea(int index) const;
		void	show_all_ideas(void) const;
};
std::ostream& operator<<(std::ostream &out, const Brain &other);

#endif /* BRAIN_HPP */
