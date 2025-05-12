/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:09:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/12 13:00:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class Bureaucrat;

Form::Form(void): name("aleatory_form"), is_sign(false), sign_grade(100), sign_execute(70)
{
	if (sign_grade < 1 || sign_execute < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || sign_execute > 150)
		throw GradeTooLowException();
	std::cout << "Default construtor Form called for " << name << " Form";
}

Form::~Form(void)
{
	std::cout << "Destructor called for " << name << " Form" << std::endl;
}

Form::Form(std::string name, int sign_grade, int sign_execute): name(name), sign_grade(sign_grade), sign_execute(sign_execute)
{
	if (sign_grade < 1 || sign_execute < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || sign_execute > 150)
		throw GradeTooLowException();
	std::cout << "Default input constructor called for " << name << " Form";
}

Form::Form(Form &another)
{
	if (another.getSignGrade() < 1 || another.getSignExecute() < 1)
		throw GradeTooHighException();
	if (another.getSignGrade() > 150 || another.getSignExecute() > 150)
		throw GradeTooLowException();
	std::cout << "Copy constructor called for " << name << " Form";
}

Form& Form::operator=(Form &other)
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

int	Form::getSignGrade(void) const
{
	return (sign_grade);
}

int	Form::getSignExecute(void) const
{
	return (sign_execute);
}

std::ostream& operator<<(std::ostream &out, Form &another)
{
	out << "Form: " << another.getFormName() << std::endl
		<< "Is_Sign: " << another.getIsSign() << std::endl
		<< "Sign_Grade: " << another.getSignGrade() << std::endl
		<< "Sign_Execute: " << another.getSignExecute() << std::endl;
	return (out);
}

bool	Form::getIsSign(void) const
{
	return (is_sign);
}

std::string	Form::getFormName(void) const
{
	return (name);
}

void	Form::setIsSign(bool god_decision)
{
	is_sign = god_decision;
}

void	Form::beSigned(const Bureaucrat &check)
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

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high\n");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low\n");
}
