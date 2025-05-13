/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AExam.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:26:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 13:29:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AEXAM_HPP
# define AEXAM_HPP

# include "Student.hpp"

class Student;

class	AExam
{
	private:
		const std::string target;
		int	required_grade;
		int	extra_grade;
	public:
		AExam(const std::string &target, int grade, int extra_grade);
		AExam(const AExam &exam);
		AExam& operator=(const AForm &Exam);
		virtual ~AExam(void);
		virtual void evaluate_student(const Student &student) const = 0;
		int	getExamRequiredGrade(void) const;
		int	getExamExtraGrade(void) const;
		std::string	getTarget(void) const;
		class AExamNotPassed: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class AExamImpossibleExtra: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream &out, const AExam &exam);

#endif /* AEXAM_HPP */
