/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:00:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 13:38:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Default contructor called for an Intern " << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Default destructor called for an Intern" << std::endl;
}

Intern::Intern(const Intern &another)
{
	(void)another;
	std::cout << "Copy constructor called for an Intern" << std::endl;
}

Intern&	Intern::operator=(const Intern &another)
{
	(void)another;
	std::cout << "Copy assignment called for an Intern" << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Intern &another)
{
	(void)another;
	out << "There is only an Intern '-'" << std::endl;
	return (out);
}

AForm	*Intern::makeForm(const std::string FormName, const std::string target) const
{
	if (FormName == "robotomy request")
		return new RobotomyRequestForm(target);
	else if (FormName == "presidential request")
		return new PresidentialPardonForm(target);
	else if (FormName == "shrubbery request")
		return new ShrubberyCreationForm(target);
	else
		std::cerr << "Intern said: Unrecognized Form Name, sir" << std::endl;
	return (NULL);
}
