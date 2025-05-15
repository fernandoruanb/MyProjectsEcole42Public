/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:00:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/14 11:54:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool	is_sign;
		const int	required_grade;
		const int	required_exec;
	public:
		Form(const std::string name, const int required_grade, const int required_exec);
		~Form(void);
		Form(const Form &another);
		Form& operator=(const Form &another);
		std::string	getFormName(void) const;
		void	beSigned(const Bureaucrat &attempt);
		bool	getIsSign(void) const;
		int	getRequiredGrade(void) const;
		int	getRequiredExec(void) const;
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
std::ostream& operator<<(std::ostream &out, const Form &another);

#endif /* FORM_HPP */
