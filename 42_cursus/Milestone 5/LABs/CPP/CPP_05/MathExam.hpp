/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MathExam.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:12:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 18:25:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHEXAM_HPP
# define MATHEXAM_HPP

# include "AExam.hpp"

class	MathExam: public AExam
{
	private:
		int	requiredGrade;
		int	requiredGradeExecute;
	public:
		MathExam(int requiredGrade, int requiredGradeExecute);
		~MathExam(void);
		MathExam(MathExam &exam);
		MathExam& operator=(MathExam &exam);
		void	execute_action(void) const;
		int	getRequiredGrade(void) const;
		int	getRequiredGradeExecute(void) const;
		void	evaluate_student(const Student &student) const;
		void	execute_action(const Student &check) const;
		class MathGradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class MathGradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
std::ostream&	operator<<(std::ostream &out, const MathExam &math);

#endif /* MATHEXAM_HPP */
