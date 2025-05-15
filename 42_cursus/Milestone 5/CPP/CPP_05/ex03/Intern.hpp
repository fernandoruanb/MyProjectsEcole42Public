/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:50:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 18:18:48 by fruan-ba         ###   ########.fr       */
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
		AForm*	shrubbery(const std::string& target) const;
		AForm*	robotomy(const std::string& target) const;
		AForm*	presidential(const std::string& target) const;
		AForm*	makeForm(const std::string FormName, const std::string target) const;
		typedef AForm* (Intern::*FormCreator)(const std::string &) const;
		class UnrecognizedFormMistake: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
std::ostream&	operator<<(std::ostream &out, const Intern &another);

#endif /* INTERN_HPP */
