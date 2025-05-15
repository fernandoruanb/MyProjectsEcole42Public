/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:47:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/14 21:18:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, const int required_grade, const int required_exec): name(name), is_sign(false), 
required_grade(required_grade), required_exec(required_exec)
{
	std::cout << "Default constructor called for " << this->getAFormName() << " AForm" << std::endl;
}

AForm::AForm(const AForm &form): name(form.getAFormName()), required_grade(form.getRequiredGrade()), required_exec(form.getRequiredExec())
{
	std::cout << "Copy constructor called for " << this->getAFormName() << " AForm" << std::endl;
	this->is_sign = form.getIsSign();
}

AForm&	AForm::operator=(const AForm &form)
{
	if (this != &form)
	{
		this->is_sign = form.getIsSign();
	}
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "Default destructor called for " << this->getAFormName() << " AForm" << std::endl;
}

bool	AForm::getIsSign(void) const
{
	return (is_sign);
}

int	AForm::getRequiredGrade(void) const
{
	return (required_grade);
}

int	AForm::getRequiredExec(void) const
{
	return (required_exec);
}

void	AForm::setSign(bool sign)
{
	is_sign = sign;
}

std::string	AForm::getAFormName(void) const
{
	return (name);
}

std::ostream&	operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm name: " << form.getAFormName() << std::endl
		<< "AForm Required_Grade: " << form.getRequiredGrade() << std::endl
		<< "AForm Required_Exec: " << form.getRequiredExec() << std::endl
		<< "AForm Is_Sign: " << form.getIsSign() << std::endl;
	return (out);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high. Maximum grade is 1");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low. Minimum grade is 150");
}
