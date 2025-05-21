/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:19:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 13:35:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::srand(static_cast<unsigned>(std::time(NULL)));
	try
	{
		Bureaucrat	A("Thiago", 90);
		Bureaucrat	B("Morpheus", 10);
		Bureaucrat	C("Jonathan", 1);
		ShrubberyCreationForm test("MyTreeMyLife");
		RobotomyRequestForm secondtest("Morpheus");
		PresidentialPardonForm thirdtest("Fernando");
		//Bureaucrat	C("Leonard", 0);
		//Bureaucrat	D("Mike", 2000);

		A.executeForm(test);
		test.beSigned(B);
		test.beSigned(A);
		thirdtest.beSigned(C);
		secondtest.beSigned(B);
		secondtest.beSigned(A);
		B.signForm(secondtest);
		A.signForm(secondtest);
		C.signForm(thirdtest);
		B.signForm(test);
		A.signForm(test);
		test.execute(B);
		test.execute(A);
		secondtest.execute(B);
		secondtest.execute(A);
		thirdtest.execute(C);
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
	catch (std::exception &exception)
	{
		std::cerr << "Another exception was found" << std::endl;
	}
	return (0);
}
