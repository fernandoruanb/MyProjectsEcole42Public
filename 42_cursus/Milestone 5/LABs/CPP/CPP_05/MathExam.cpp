/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MathExam.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:12:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 18:57:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MathExam.hpp"

MathExam::MathExam(int requiredGrade, int requiredGradeExecute): AExam("MathExam", requiredGrade, requiredGradeExecute), requiredGrade(requiredGrade), requiredGradeExecute(requiredGradeExecute)
{
	if (requiredGrade < 1 || requiredGradeExecute < 1)
		throw MathGradeTooHighException();
	if (requiredGrade > 150 || requiredGradeExecute > 150)
		throw MathGradeTooLowException();
	std::cout << "Default MathExam tester called" << std::endl;
}

MathExam::~MathExam(void)
{
	std::cout << "Destructor called for MathExam" << std::endl;
}

void	MathExam::evaluate_student(const Student &student) const
{
	if (student.getGrade() <= this->getRequiredGrade())
	{
		std::cout << "The student " << student.getName() << " passed" << std::endl;
	}
	else
		std::cout << "The student " << student.getName() << " didn't pass" << std::endl;
}

int	MathExam::getRequiredGrade(void) const
{
	return (requiredGrade);
}

int	MathExam::getRequiredGradeExecute(void) const
{
	return (requiredGradeExecute);
}

void	MathExam::execute_action(const Student &check) const
{
	if (check.getGrade() <= getRequiredGrade())
	{
		if (check.getGrade() <= this->requiredGradeExecute)
			std::cout << "The student gives a party for everybody!!!" << std::endl;
	}
	else if (check.getGrade() > getRequiredGrade())
		std::cout << "The student didn't be approve to check the extra" << std::endl;
	else if (check.getGrade() <= getRequiredGrade())
		std::cout << "The student got grade but not enough for the extra" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const MathExam &math)
{
	out << "MathExam Required Grade: " << math.getRequiredGrade() << std::endl
		<< "MathExam Extra Execute: " << math.getRequiredGradeExecute() << std::endl;
	return (out);
}

const char	*MathExam::MathGradeTooLowException::what() const throw()
{
	return ("Math Exam minimum grade is 150");
}

const char	*MathExam::MathGradeTooHighException::what() const throw()
{
	return ("Math Exam maximum grade is 1");
}
