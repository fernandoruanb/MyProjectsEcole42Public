/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:09:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/10 22:36:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): name("aleatory_form"), is_sign(false), sign_grade(100), sign_execute(70)
{
	if (sign_grade < 1 || sign_execute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (sign_grade > 150 || sign_execute > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Default construtor Form called for " << name << " Form";
}

Form::~Form(void)
{
	std::cout << "Destructor called for " << name << " Form" << std::endl;
}

Form::Form(std::string name, bool is_sign, int sign_grade, int sign_execute): name(name), is_sign(is_sign), sign_grade(sign_grade), sign_execute(sign_execute)
{
	if (sign_grade < 1 || sign_execute < 1)
		throw Bureaucrat::GradeTooHighException();
	if (sign_grade > 150 || sign_execute > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Default input constructor called for " << name << " Form";
}

Form::Form(Form &another)
{
	std::cout << "Copy constructor called for " << name << " Form";
}

std::ostream& operator=(Form &other)
{
	if (this != &other)
	{
		this->is_sign = other.is_sign;
		this->sign_grade = other.sign_grade;
		this->sign_execute = other.sign_execute;
	}
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
