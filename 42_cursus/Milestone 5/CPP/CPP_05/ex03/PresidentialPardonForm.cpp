/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:15:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 18:36:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm(target, 25, 5), target(target)
{
	std::cout << "Default constructor called for " << this->getTarget() << " PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor called for " << this->getTarget() << " PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &another): AForm(another.getTarget(), 25, 5), target(another.getTarget())
{
	std::cout << "Copy constructor called for " << this->getTarget() << " PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& another)
{
	(void)another;
	std::cout << "Copy assignment operator called for " << this->getTarget() << " PresidentialPardonForm" << std::endl;
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (target);
}

void	PresidentialPardonForm::beSigned(const Bureaucrat &attempt)
{
	if (attempt.getGrade() <= this->getRequiredGrade())
		setSign(true);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSign() && executor.getGrade() <= this->getRequiredExec())
	{
		std::cout << executor.getName() << " execute PresidentialPardonForm" << std::endl;;
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox " << std::endl;
	}
	else
		std::cerr << executor.getName() << " didn't execute PresidentialPardonForm" << std::endl;
}

std::ostream&	operator<<(std::ostream &out, const PresidentialPardonForm &another)
{
	out << "PresidentialPardonForm target " << another.getTarget() << std::endl;
	return (out);
}
