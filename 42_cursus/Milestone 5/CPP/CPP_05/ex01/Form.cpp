/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:09:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/11 13:08:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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

Form::Form(std::string name, bool is_sign, int sign_grade, int sign_execute): name(name), is_sign(is_sign), sign_grade(sign_grade), sign_execute(sign_execute)
{
	if (sign_grade < 1 || sign_execute < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || sign_execute > 150)
		throw GradeTooLowException();
	std::cout << "Default input constructor called for " << name << " Form";
}

Form::Form(Form &another)
{
	if (another.sign_grade < 1 || another.sign_execute < 1)
		throw GradeTooHighException();
	if (another.sign_grade > 150 || sign_execute > 150)
		throw GradeTooLowException();
	std::cout << "Copy constructor called for " << name << " Form";
}

Form& Form::operator=(Form &other)
{
	if (this != &other)
	{
		if (other.sign_grade < 1 || other.sign_execute < 1)
			throw GradeTooHighException();
		if (other.sign_grade > 150 || other.sign_execute > 150)
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
	out << "Form: " << another.getFormName();
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

Form& Form::operator--(void)
{
	if (sign_grade >= 150 || sign_execute >= 150)
		throw GradeTooLowException();
	sign_grade++;
	sign_execute++;
	return (*this);
}

Form& Form::operator++(void)
{
	if (sign_grade < 1 || sign_execute < 1)
		throw GradeTooHighException();
	sign_grade--;
	sign_execute--;
	return (*this);
}

Form Form::operator--(int)
{
	Form result(*this);

	if (sign_grade >= 150 || sign_execute >= 150)
		throw GradeTooLowException();
	++(*this);
	return (result);
}

Form Form::operator++(int)
{
	Form result(*this);

	if (sign_grade < 1 || sign_execute < 1)
		throw GradeTooHighException();
	--(*this);
	return (result);
}

void	Form::setIsSign(bool god_decision)
{
	is_sign = god_decision;
}

void	Form::beSigned(const Form &check)
{
	if (check.getIsSign())
		std::cout << "The Form is signed" << std::endl;
	else
		std::cout << "The Form isn't signed" << std::endl;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high\n");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low\n");
}
