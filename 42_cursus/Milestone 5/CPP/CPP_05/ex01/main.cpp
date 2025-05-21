/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:53:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 13:34:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat A("Thiago", 10);
		Bureaucrat B("Robert", 80);
		Form Payment("Payment", 50, 20);
		//Form Action("Action", 1500, 20);
		//Form Activity("Activity", 0, 20);
		//Bureaucrat C("Morpheus", 8000);
		//Bureaucrat D("Indiana Jones", 0);

		Payment.beSigned(A);
		A.signForm(Payment);
		std::cout << A << std::endl;
		++A;
		std::cout << A << std::endl;
		--A;
		std::cout << A << std::endl;
		A++;
		std::cout << A << std::endl;
		A--;
		std::cout << A << std::endl;
		B.incrementGrade();
		B.decrementGrade();
		std::cout << B << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (Form::GradeTooHighException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (Form::GradeTooLowException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cerr << "Another exception was found!" << std::endl;
	}
	return (0);
}
