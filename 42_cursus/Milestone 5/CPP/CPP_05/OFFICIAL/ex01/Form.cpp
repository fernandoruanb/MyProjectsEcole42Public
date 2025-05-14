/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:14:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:36 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int required_grade, const int required_exec): name(name), is_sign(false),
 required_grade(required_grade), required_exec(required_exec)
{
	if (required_grade < 1 || required_exec < 1)
		throw GradeTooHighException();
	if (required_grade > 150 || required_exec > 150)
		throw GradeTooLowException();
	std::cout << "Default Form constructor called for " << this->getFormName() << " Form" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Default destructor called for " << this->getFormName() << " Form" << std::endl;
}

Form::Form(const Form &another): name(another.getFormName()), is_sign(another.getIsSign()), required_grade(another.getRequiredGrade()),
	required_exec(another.getRequiredExec())
{
	std::cout << "Copy constructor called for " << this->getFormName() << " Form" << std::endl;
}

Form&	Form::operator=(const Form &another)
{
	if (this != &another)
	{
		this->is_sign = another.getIsSign();
	}
	return (*this);
}

std::string	Form::getFormName(void) const
{
	return (name);
}

void	Form::beSigned(const Bureaucrat &attempt)
{
	if (attempt.getGrade() <= this->getRequiredGrade())
		is_sign = 1;
}

bool	Form::getIsSign(void) const
{
	return (is_sign);
}

int	Form::getRequiredGrade(void) const
{
	return (required_grade);
}

int	Form::getRequiredExec(void) const
{
	return (required_exec);
}

std::ostream&	operator<<(std::ostream &out, const Form &another)
{
	out << "Form name: " << another.getFormName() << std::endl
		<< " Form signed: " << another.getIsSign() << std::endl
		<< " Form required grade: " << another.getRequiredGrade() << std::endl
		<< " Form required exec: " << another.getRequiredExec() << std::endl;
	return (out);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high! Maximum grade is 1");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low! Minimum grade is 150");
}
