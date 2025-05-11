/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:28:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/11 13:22:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Robson", 3);
		Form form1("Formula 1", false, 250, 120);
		Bureaucrat b;

		std::cout << a.getName() << std::endl;
		std::cout << b.getName() << std::endl;
		std::cout << a.getGrade() << std::endl;
		++a;
		std::cout << a << std::endl;
		a.signForm(form1);
		form1.beSigned(form1);
		std::cout << a.getGrade() << std::endl;
		std::cout << b.getGrade() << std::endl;
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
