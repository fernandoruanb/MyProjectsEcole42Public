/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:24:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 11:57:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Default constructor called for " << name << " Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called for " << this->getName() << " Bureaucrat" << std::endl;
}

void	Bureaucrat::incrementGrade(void)
{
	++(*this);
}

void	Bureaucrat::decrementGrade(void)
{
	--(*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &another): name(another.getName()), grade(another.getGrade())
{
	(void)another;
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &another)
{
	if (this != &another)
	{
		this->grade = another.getGrade();
	}
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (name);
}

int	Bureaucrat::getGrade(void) const
{
	return (grade);
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
	Bureaucrat result(*this);

	if (this->getGrade() >= 150)
		throw GradeTooLowException();
	--(*this);
	return (result);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat result(*this);

	if (this->getGrade() < 1)
		throw GradeTooHighException();
	++(*this);
	return (result);
}

Bureaucrat::Bureaucrat(void): name("Bob"), grade(0) {}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &another)
{
	out << another.getName() << ", bureaucrat grade " << another.getGrade() << std::endl;
	return (out);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high! Maximum grade is 1");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low! Minimum grade is 150");
}
