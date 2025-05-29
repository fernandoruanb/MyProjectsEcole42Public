/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:25:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/29 11:58:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int	grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &another);
		Bureaucrat& operator=(const Bureaucrat &another);
		Bureaucrat& operator--(void);
		Bureaucrat& operator++(void);
		Bureaucrat operator--(int);
		Bureaucrat operator++(int);
		void	incrementGrade(void);
		void	decrementGrade(void);
		std::string	getName(void) const;
		int	getGrade(void) const;
		void	signForm(const AForm &attempt);
		void	executeForm(AForm const & form);
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
std::ostream& operator<<(std::ostream &out, const Bureaucrat &another);

#endif /* BUREAUCRAT_HPP */
