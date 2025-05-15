/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:09:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 10:28:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target, int required_grade, int required_exec): AForm(target, required_grade, required_exec), target(target)
{
	if (required_grade < 1 || required_exec < 1)
		throw GradeTooHighException();
	if (required_grade > 150 || required_exec > 150)
		throw GradeTooLowException();
	std::cout << "Default constructor called for " << this->getTarget() << " RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called for " << this->getTarget() << " RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &another): AForm(another.getTarget(), another.getRequiredGrade(), another.getRequiredExec()), target(another.getTarget())
{
	std::cout << "Copy constructor called for " << this->getTarget() << " RobotomyRequestForm" << std::endl;
}

void	RobotomyRequestForm::beSigned(const Bureaucrat &attempt)
{
	if (attempt.getGrade() <= this->getRequiredGrade())
		setSign(true);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getRequiredExec())
	{
		std::cout << executor.getName() << " executes " << this->getTarget() << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;
	}
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (target);
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &another)
{
	(void)another;
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const RobotomyRequestForm &another)
{
	out << "RobotomyRequestForm target: " << another.getTarget() << std::endl
		<< "RobotomyRequestForm Required_Grade: " << another.getRequiredGrade() << std::endl
		<< "RobotomyRequestForm Required_Exec: " << another.getRequiredExec() << std::endl
		<< "RobotomyRequestForm Is_Sign: " << another.getIsSign() << std::endl;
	return (out);
}
