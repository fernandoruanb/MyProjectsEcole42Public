/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AExam.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:02:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 18:39:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AExam.hpp"

AExam::AExam(const std::string &target, int required_grade, int extra_grade): target(target), pass(false), required_grade(required_grade), extra_grade(extra_grade)
{
	std::cout << "Default construtor called for " << this->getExamTarget() << " Exam" << std::endl;
}

AExam::~AExam(void)
{
	std::cout << "Destructor called for " << this->getExamTarget() << " Exam" << std::endl;
}

AExam& AExam::operator=(const AExam &Exam)
{
	if (this != &Exam)
	{
		this->required_grade = Exam.getExamRequiredGrade();
		this->extra_grade = Exam.getExamExtraGrade();
	}
	return (*this);
}

std::string	AExam::getExamTarget(void) const
{
	return (target);
}

int	AExam::getExamRequiredGrade(void) const
{
	return (required_grade);
}

int	AExam::getExamExtraGrade(void) const
{
	return (extra_grade);
}

std::ostream&	operator<<(std::ostream &out, const AExam &Exam)
{
	out << "Exam: " << Exam.getExamTarget() << std::endl;
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
