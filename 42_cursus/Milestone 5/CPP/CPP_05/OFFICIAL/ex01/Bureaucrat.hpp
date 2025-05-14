/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:23:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 20:37:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class	Bureaucrat
{
	private:
		const std::string	name;
		int	grade;
	public:
		Bureaucrat(const std::string, int grade);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat &another);
		Bureaucrat& operator=(Bureaucrat &another);
		Bureaucrat& operator++(void);
		Bureaucrat& operator--(void);
		Bureaucrat operator++(int);
		Bureaucrat operator--(int);
		int	getGrade(void) const;
		std::string	getName(void) const;
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		}
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what const throw();
		}
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat &other);

#endif /* BUREAUCRAT_HPP */
