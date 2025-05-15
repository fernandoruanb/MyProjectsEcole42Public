/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:09:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 18:36:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm(target, 72, 45), target(target)
{
	if (this->getRequiredGrade() < 1 || this->getRequiredExec() < 1)
		throw GradeTooHighException();
	if (this->getRequiredGrade() > 150 || this->getRequiredExec() > 150)
		throw GradeTooLowException();
	std::cout << "Default constructor called for " << this->getTarget() << " RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called for " << this->getTarget() << " RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &another): AForm(another.getTarget(), 72, 45), target(another.getTarget())
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
	if (this->getIsSign() && executor.getGrade() <= this->getRequiredExec())
	{
		std::cout << executor.getName() << " executes " << this->getTarget() << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;
	}
	else
		std::cerr << executor.getName() << " didn't execute the RobotomyRequestForm unfortunately" << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (target);
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &another)
{
	(void)another;
	std::cout << "Copy assignment called for " << this->getTarget() << " Form" << std::endl;
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
