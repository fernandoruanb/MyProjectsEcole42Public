/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:16:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 19:23:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class	Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat &another);
		Bureaucrat& operator=(Bureaucrat &another);
		Bureaucrat& operator--(void);
		Bureaucrat& operator++(void);
		Bureaucrat operator--(int);
		Bureaucrat operator++(int);
		std::string	getName(void) const;
		int	getGrade(void) const;
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() throw();
		}
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() throw();
		}
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat &another);

#endif /* BUREAUCRAT_HPP */
