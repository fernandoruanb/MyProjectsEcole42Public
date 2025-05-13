/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MathExam.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:12:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 13:26:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHEXAM_HPP
# define MATHEXAM_HPP

class	MathExam
{
	private:
		int	requiredGrade;
		int	requiredGradeExecute;
	public:
		MathExam(AForm("Mathematics", 100, 70));
		~MathExam(void);
		MathExam(MathExam &exam);
		MathExam& operator=(MathExam &exam);
};
std::ostream&	operator<<(std::ostream &out, const MathExam &math);

#endif /* MATHEXAM_HPP */
