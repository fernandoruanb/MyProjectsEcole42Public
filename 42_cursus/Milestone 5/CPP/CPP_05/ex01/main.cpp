/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:28:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/12 12:30:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Robson", 10);
		Form form1("Formula 1", 20, 10);
		Bureaucrat b;

		std::cout << a.getName() << std::endl;
		std::cout << b.getName() << std::endl;
		std::cout << "Bureaucrat A first grade: " << a.getGrade() << std::endl;
		++a;
		std::cout << "New grade: " <<  a << std::endl;
		a.signForm(form1);
		b.signForm(form1);
		std::cout << form1;
		form1.beSigned(a);
		form1.beSigned(b);
		a.signForm(form1);
		b.signForm(form1);
		std::cout << "Last A grade: " << a.getGrade() << std::endl;
		std::cout << "Last B grade: " << b.getGrade() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &exception)
	{
		std::cerr << "Grade is too low" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << "Grade is too high" << std::endl;
	}
	catch (const Form::GradeTooLowException &exception)
	{
		std::cerr << exception.what();
	}
	catch (const Form::GradeTooHighException &exception)
	{
		std::cerr << exception.what();
	}
	catch (const std::exception &exception)
	{
		std::cerr << "There is other exception from exceptions" << std::endl;
	}
	return (0);
}
