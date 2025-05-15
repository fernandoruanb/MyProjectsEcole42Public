/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:50:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 13:38:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Bureaucrat;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;
class AForm;

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &another);
		Intern& operator=(const Intern &another);
		AForm*	makeForm(const std::string FormName, const std::string target) const;
};
std::ostream&	operator<<(std::ostream &out, const Intern &another);

#endif /* INTERN_HPP */
