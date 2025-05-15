/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:19:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 10:51:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	std::srand(static_cast<unsigned>(std::time(NULL)));
	try
	{
		Bureaucrat	A("Thiago", 90);
		Bureaucrat	B("Morpheus", 10);
		ShrubberyCreationForm test("Form");
		RobotomyRequestForm secondtest("Form2");
		//Bureaucrat	C("Leonard", 0);
		//Bureaucrat	D("Mike", 2000);

		test.beSigned(B);
		test.beSigned(A);
		secondtest.beSigned(B);
		secondtest.beSigned(A);
		B.signForm(secondtest);
		A.signForm(secondtest);
		B.signForm(test);
		A.signForm(test);
		test.execute(B);
		test.execute(A);
		secondtest.execute(B);
		secondtest.execute(A);
		std::cout << A << std::endl;
		++A;
		std::cout << A << std::endl;
		--A;
		std::cout << A << std::endl;
		A++;
		std::cout << A << std::endl;
		A--;
		std::cout << A << std::endl;
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
	catch (std::exception &exception)
	{
		std::cerr << "Another exception was found" << std::endl;
	}
	return (0);
}
