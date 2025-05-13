/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:09:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/12 12:59:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class Bureaucrat;

AForm::AForm(void): name("aleatory_form"), is_sign(false), sign_grade(100), sign_execute(70)
{
	if (sign_grade < 1 || sign_execute < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || sign_execute > 150)
		throw GradeTooLowException();
	std::cout << "Default construtor AForm called for " << name << " Form";
}

AForm::~AForm(void)
{
	std::cout << "Destructor called for " << name << " AForm" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int sign_execute): name(name), is_sign(false), sign_grade(sign_grade), sign_execute(sign_execute)
{
	if (sign_grade < 1 || sign_execute < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || sign_execute > 150)
		throw GradeTooLowException();
	std::cout << "Default input constructor called for " << name << " AForm";
}

AForm::AForm(AForm &another)
{
	if (another.getSignGrade() < 1 || another.getSignExecute() < 1)
		throw GradeTooHighException();
	if (another.getSignGrade() > 150 || another.getSignExecute() > 150)
		throw GradeTooLowException();
	std::cout << "Copy constructor called for " << name << " AForm";
}

AForm& AForm::operator=(AForm &other)
{
	if (this != &other)
	{
		if (other.getSignGrade() < 1 || other.getSignExecute() < 1)
			throw GradeTooHighException();
		if (other.getSignGrade() > 150 || other.getSignExecute() > 150)
			throw GradeTooLowException();
		this->is_sign = other.getIsSign();
		this->sign_grade = other.getSignGrade();
		this->sign_execute = other.getSignExecute();
	}
	return (*this);
}

int	AForm::getSignGrade(void) const
{
	return (sign_grade);
}

int	AForm::getSignExecute(void) const
{
	return (sign_execute);
}

std::ostream& operator<<(std::ostream &out, AForm &another)
{
	out << "AForm: " << another.getFormName() << std::endl
		<< "Is_Sign: " << another.getIsSign() << std::endl
		<< "Sign_Grade: " << another.getSignGrade() << std::endl
		<< "Sign_Execute: " << another.getSignExecute() << std::endl;
	return (out);
}

bool	AForm::getIsSign(void) const
{
	return (is_sign);
}

std::string	AForm::getFormName(void) const
{
	return (name);
}

void	AForm::setIsSign(bool god_decision)
{
	is_sign = god_decision;
}

void	AForm::beSigned(const Bureaucrat &check)
{
	if (check.getGrade() <= this->sign_grade)
	{
		std::cout << check.getName() << " signed " << this->name << std::endl;
		this->is_sign = 1;
	}
	else
		std::cout << check.getName() << " couldn't sign " << this->name 
			<< " because low grade" << std::endl;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high\n");
}

const char	*AForm::FormIsNotSigned::what() const throw()
{
	return ("Don't have enough grade to sign the Form\n");
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!executor.beSigned())
		throw FormIsNotSigned();
	if (executor.getGrade() > this->sign_execute)
		throw GradeTooLowException();
	this->execute_power();
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low\n");
}
