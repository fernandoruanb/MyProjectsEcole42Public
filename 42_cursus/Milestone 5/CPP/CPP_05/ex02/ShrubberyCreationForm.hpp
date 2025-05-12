/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:51:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/12 15:13:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string target;
		void	draw_ascii_tree(std::string file);
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm &other);
		ShrubberyCreationForm(ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);
		std::string	getTarget(void) const;
		void execute_tree(const Bureaucrat &check);
};
std::ostream& operator<<(std::ostream &out, ShrubberyCreationForm &other);

#endif /* SHRUBBERYCREATIONFORM_HPP */
