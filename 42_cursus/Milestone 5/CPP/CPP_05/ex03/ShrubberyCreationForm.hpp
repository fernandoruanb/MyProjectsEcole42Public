/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:42:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 10:51:36 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string target;
	public:
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &another);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &another);
		std::string	getTarget(void) const;
		void	beSigned(const Bureaucrat &attempt);
		void	execute(Bureaucrat const & executor) const;
};
std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &another);

#endif /* SHRUBBERYCREATIONFORM_HPP */
