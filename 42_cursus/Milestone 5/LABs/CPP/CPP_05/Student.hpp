/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:58:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 11:06:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENT_HPP
# define STUDENT_HPP

# include <iostream>
# include <exception>

class Student
{
	private:
		const std::string name;
		int	grade;
	public:
		Student(void);
		Student(const std::string name, int grade);
		~Student(void);
		Student(const Student &another);
		Student& operator=(const Student &another);
		Student operator++(int);
		Student operator--(int);
		Student& operator++(void);
		Student& operator--(void);
		int getGrade(void) const;
		std::string getName(void) const;
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
std::ostream& operator<<(std::ostream &out, const Student &another);

#endif /* STUDENT_HPP */
