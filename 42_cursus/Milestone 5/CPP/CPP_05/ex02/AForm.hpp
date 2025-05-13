/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:10:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/12 12:58:10 by fruan-ba         ###   ########.fr       */
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
		AForm(std::string name, int sign_grade, int sign_execute);
		AForm(AForm &another);
		virtual ~AForm(void);
		AForm& operator=(AForm &other);
		void	beSigned(const Bureaucrat &check);
		std::string	getFormName(void) const;
		bool	getIsSign(void) const;
		int	getSignGrade(void) const;
		int	getSignExecute(void) const;
		void	setIsSign(bool god_decision);
		void	execute_power(const &executor) const;
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
		class FormIsNotSigned: public std::exception
		{
			public:
				virtual const char *what() const throw();
		}
};
std::ostream& operator<<(std::ostream &out, AForm &another);

#endif /* FORM_HPP */
