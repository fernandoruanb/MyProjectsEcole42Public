/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:37:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 11:57:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("Bob"), grade(0) {}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Default constructor called for " << this->getName() << " bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called for " << this->getName() << " bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &another): name(another.getName()), grade(another.getGrade())
{
	(void)another;
	std::cout << "Copy constructor called" << std::endl;
}

void	Bureaucrat::incrementGrade(void)
{
	++(*this);
}

void	Bureaucrat::decrementGrade(void)
{
	--(*this);
}
int	Bureaucrat::getGrade(void) const
{
	return (grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (name);
}

Bureaucrat&	Bureaucrat::operator--(void)
{
	if (this->getGrade() >= 150)
		throw GradeTooLowException();
	++grade;
	return (*this);
}

Bureaucrat&	Bureaucrat::operator++(void)
{
	if (this->getGrade() <= 1)
		throw GradeTooHighException();
	--grade;
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat	result(*this);

	if (this->getGrade() >= 150)
		throw GradeTooLowException();
	--(*this);
	return (result);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat	result(*this);

	if (this->getGrade() <= 1)
		throw GradeTooHighException();
	++(*this);
	return (result);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &another)
{
	out << another.getName() << " bureaucrat grade " << another.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::signForm(const Form &form)
{
	if (this->getGrade() > form.getRequiredGrade())
	{
		std::cerr << this->getName() << " couldn't sign " << form.getFormName() << " because " << "the grade" << std::endl;
		return ;
	}
	if (form.getIsSign())
		std::cout << this->getName() << " signed " << form.getFormName() << std::endl;
	else
		std::cerr << this->getName() << " couldn't sign " << form.getFormName()
			<< " because " << "the grade" << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high. Maximum grade is 1");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low. Minimum grade is 150");
}
