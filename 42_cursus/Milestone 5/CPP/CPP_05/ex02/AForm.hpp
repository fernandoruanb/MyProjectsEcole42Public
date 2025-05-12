/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:10:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/12 11:18:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool	is_sign;
		int	sign_grade;
		int	sign_execute;
	public:
		AForm(void);
		AForm(std::string name, bool is_sign, int sign_grade, int sign_execute);
		AForm(AForm &another);
		virtual ~AForm(void);
		virtual AForm& operator=(AForm &other) = 0;
		virtual AForm& operator--(void) = 0;
		virtual AForm& operator++(void) = 0;
		virtual AForm& operator--(int) = 0;
		virtual AForm& operator++(int) = 0;
		virtual void	beSigned(const Bureaucrat &check) = 0;
		std::string	getFormName(void) const;
		bool	getIsSign(void) const;
		int	getSignGrade(void) const;
		int	getSignExecute(void) const;
		void	setIsSign(bool god_decision);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream &out, AForm &another);

#endif /* FORM_HPP */
