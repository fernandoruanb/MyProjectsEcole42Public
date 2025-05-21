/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:19:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 13:35:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::srand(static_cast<unsigned>(std::time(NULL)));
	try
	{
		Bureaucrat	A("Thiago", 90);
		Bureaucrat	B("Morpheus", 10);
		Bureaucrat	C("Jonathan", 1);
		Intern	crazyMan;
		AForm*	work;
		//AForm*	mistake;
		ShrubberyCreationForm test("MyTreeMyLife");
		RobotomyRequestForm secondtest("Morpheus");
		PresidentialPardonForm thirdtest("Fernando");
		//Bureaucrat	C("Leonard", 0);
		//Bureaucrat	D("Mike", 2000);

		//mistake = crazyMan.makeForm("mistake", "mistakeMan");
		work = crazyMan.makeForm("robotomy request", "crazyMan");
		//if (mistake != NULL)
		//	mistake->beSigned(A);
		work->beSigned(A);
		A.signForm(*work);
		A.executeForm(*work);
		A.executeForm(test);
		//if (mistake != NULL)
		//A.executeForm(*mistake);
		test.beSigned(B);
		test.beSigned(A);
		thirdtest.beSigned(C);
		C.signForm(thirdtest);
		secondtest.beSigned(B);
		B.signForm(secondtest);
		secondtest.beSigned(A);
		A.signForm(secondtest);
		B.signForm(test);
		A.signForm(test);
		test.execute(B);
		test.execute(A);
		secondtest.execute(B);
		secondtest.execute(A);
		thirdtest.execute(C);
		delete work;
		//delete mistake;
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
		std::cout << "B: " << B << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (Intern::UnrecognizedFormMistake &exception)
	{
		std::cerr << exception.what() << std::endl;	
	}
	catch (std::exception &exception)
	{
		std::cerr << "Another exception was found" << std::endl;
	}
	return (0);
}
