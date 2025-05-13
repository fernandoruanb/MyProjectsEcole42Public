/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:16:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 12:02:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"

Student::Student(void): name("Jonathan"), grade(150)
{
	std::cout << "Default contructor called for " << name << " Student" << std::endl;
}

Student::~Student(void)
{
	std::cout << "Destructor called for " << name << " Student" << std::endl;
}

Student::Student(const std::string name, int grade): name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Default constructor called for " << name << " Student" << std::endl;
}

Student::Student(const Student &another): name(another.getName()), grade(another.getGrade())
{
	std::cout << "Copy constructor called for " << another.getName() << " Student" << std::endl;
	this->grade = another.getGrade();
}

Student&	Student::operator=(const Student &another)
{
	if (this != &another)
	{
		this->grade = another.getGrade();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Student &another)
{
	out << another.getName() << " Student has grade " << another.getGrade() << std::endl;
	return (out);
}

Student&	Student::operator++(void)
{
	if (this->getGrade() < 1)
		throw GradeTooHighException();
	if (this->getGrade() >= 150)
		throw GradeTooLowException();
	grade--;
	return (*this);
}

Student&	Student::operator--(void)
{
	if (this->getGrade() <= 1)
		throw GradeTooHighException();
	if (this->getGrade() >= 150)
		throw GradeTooLowException();
	grade++;
	return (*this);
}

Student	Student::operator++(int)
{
	Student	result(*this);

	if (this->getGrade() < 1)
		throw GradeTooHighException();
	if (this->getGrade() >= 150)
		throw GradeTooLowException();
	--(*this);
	return (result);
}

Student Student::operator--(int)
{
	Student result(*this);

	if (this->getGrade() < 1)
		throw GradeTooHighException();
	if (this->getGrade() >= 150)
		throw GradeTooLowException();
	++(*this);
	return (result);
}

int	Student::getGrade(void) const
{
	return (this->grade);
}

std::string	Student::getName(void) const
{
	return (this->name);
}

const char	*Student::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Student::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
