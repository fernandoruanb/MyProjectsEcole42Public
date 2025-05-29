/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:46:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 11:59:16 by fruan-ba         ###   ########.fr       */
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
	std::cout << "Default constructor called for " << this->getName() << " Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called for " << this->getName() << " Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.getName()), grade(other.getGrade())
{
	std::cout << "Copy constructor called for " << this->getName() << " Bureaucrat" << std::endl;
	this->grade = other.getGrade();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &another)
{
	if (this != &another)
	{
		this->grade = another.getGrade();
	}
	return (*this);
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

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &another)
{
	out << another.getName() << " bureaucrat grade " << another.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::signForm(const AForm &attempt)
{
	if (this->getGrade() > attempt.getRequiredGrade())
	{
		std::cerr << this->getName() << " couldn't sign " << attempt.getAFormName() << " because the grade" << std::endl;
		return ;
	}
	if (attempt.getIsSign())
		std::cout << this->getName() << " signed " << attempt.getAFormName() << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << attempt.getAFormName() << " because the grade" << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return (name);
}

int	Bureaucrat::getGrade(void) const
{
	return (grade);
}

void	Bureaucrat::executeForm(AForm const & form)
{
	if (form.getIsSign() && this->getGrade() <= form.getRequiredExec())
		form.execute(*this);
}

void	Bureaucrat::incrementGrade(void)
{
	++(*this);
}

void	Bureaucrat::decrementGrade(void)
{
	--(*this);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too High! Maximum grade is 1");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too Low! Minimum grade is 150");
}
