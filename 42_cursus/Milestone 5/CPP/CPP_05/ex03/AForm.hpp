/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:11:52 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 13:35:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class	AForm
{
	private:
		const std::string	name;
		bool	is_sign;
		const int	required_grade;
		const int	required_exec;
	public:
		AForm(const std::string name, const int required_grade, const int required_exec);
		virtual ~AForm(void);
		AForm(const AForm &another);
		AForm&	operator=(const AForm &another);
		virtual void	beSigned(const Bureaucrat &attempt) = 0;
		virtual void	execute(Bureaucrat const & executor) const = 0;
		int	getRequiredGrade(void) const;
		int	getRequiredExec(void) const;
		bool	getIsSign(void) const;
		void	setSign(bool sign);
		std::string	getAFormName(void) const;
		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif /* AFORM_HPP */
