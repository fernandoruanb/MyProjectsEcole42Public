/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AExam.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:02:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 13:28:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AExam.hpp"

AExam::AExam(const std::string &target, int required_grade, int required_extra): target(target), required_grade(grade),
	required_extra(required_extra);
{
	std::cout << "Default construtor called for " << name << " Exam" << std::endl;
}

AExam::~AExam(void)
{
	std::cout << "Destructor called for " << name << " Exam" << std::endl;
}

AExam& AForm::operator=(const AForm &Exam)
{
	if (this != &Exam)
	{
		this->grade = Exam.getExamGrade();
	}
	return (*this);
}

std::string	AForm::getTarget(void) const
{
	return (target);
}

int	AForm::getExamRequiredGrade(void) const
{
	return (required_grade);
}

int	AForm::getExamExtraGrade(void) const
{
	return (extra_grade);
}

std::ostream&	operator<<(std::ostream &out, const AForm &Exam)
{
	out << "Exam: " << Exam.getExamName() << std::endl;
	return (out);
}

const char	*AExam::AExamNotPassed::what() const throw()
{
	return ("The student doesn't have enough grade to pass in this Exam");
}

const char	*AExam::AExamImpossibleExtra::what() const throw()
{
	return ("The student passed but not with enough grade to execute an extra");
}
