/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:55:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/10 20:02:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("default_bureaucrat"), grade(150)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Default Bureaucrat construtor called for " << name << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Copy constructor called for " << name << " Bureaucrat";
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Default input constructor called for " << name << " Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Default destructor called for " << name << " Bureaucrat" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.getGrade();
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat	result(*this);

	if (grade < 1)
		throw GradeTooHighException();
	--(*this);
	return (result);
}

Bureaucrat&	Bureaucrat::operator++(void)
{
	if (grade < 1)
		throw GradeTooHighException();
	grade--;
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat result(*this);

	if (grade >= 150)
		throw GradeTooLowException();
	++(*this);
	return (result);
}

Bureaucrat&	Bureaucrat::operator--(void)
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return (out);
}

std::string	Bureaucrat::getName(void) const
{
	return (name);
}

int	Bureaucrat::getGrade(void) const
{
	return (grade);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!\n");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!\n");
}
