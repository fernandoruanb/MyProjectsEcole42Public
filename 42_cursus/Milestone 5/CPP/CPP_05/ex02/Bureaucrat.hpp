/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:25:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/12 11:03:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <exception>
# include <iostream>

class AForm;

class	Bureaucrat
{
	private:
		const std::string	name;
		int	grade;
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat& operator=(const Bureaucrat &other);
		Bureaucrat& operator++(void);
		Bureaucrat& operator--(void);
		Bureaucrat operator--(int);
		Bureaucrat operator++(int);
		Bureaucrat(Bureaucrat &other);
		std::string	getName(void) const;
		void	signForm(AForm &form) const;
		int	getGrade(void) const;
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
std::ostream& operator<<(std::ostream &out, const Bureaucrat &other);

#endif /* BUREAUCRAT_HPP */
