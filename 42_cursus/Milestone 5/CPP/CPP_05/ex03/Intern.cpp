/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:00:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 18:23:37 by fruan-ba         ###   ########.fr       */
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

AForm	*Intern::shrubbery(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::robotomy(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::presidential(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

const char	*Intern::UnrecognizedFormMistake::what() const throw()
{
	return ("Intern didn't find the form");
}

AForm	*Intern::makeForm(const std::string FormName, const std::string target) const
{
	static const char	*forms[3] = {"shrubbery request", "robotomy request", "presidential request"};
	int	index;

	static FormCreator creators[3] =
	{
		&Intern::shrubbery,
		&Intern::robotomy,
		&Intern::presidential,
	};
	index = 0;
	while (index < 3)
	{
		if (FormName == forms[index])
		{
			std::cout << "Intern creates " << forms[index] << std::endl;
			return(this->*creators[index])(target);
		}
		index++;
	}
	if (index == 3)
		throw UnrecognizedFormMistake();
	return (NULL);
}
