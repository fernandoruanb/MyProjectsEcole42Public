/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:09:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/14 22:52:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target, int required_grade, int required_exec): target(target), AForm(target, required_grade, required_exec)
{
	std::cout << "Default constructor called for " << this->getTarget() << " RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor called for " << this->getTarget() << " RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &another): AForm(another.getTarget(), another.getRequiredGrade(), anotherRequiredExec()), target(another.getTarget())
{
	std::cout << "Copy constructor called for " << this->getTarget() << " RobotomyRequestForm" << std::endl;
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
