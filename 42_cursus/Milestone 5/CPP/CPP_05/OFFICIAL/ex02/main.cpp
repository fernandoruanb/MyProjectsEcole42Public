/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:19:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/14 21:22:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	A("Thiago", 100);
		Bureaucrat	B("Morpheus", 10);
		ShrubberyCreationForm test("Form", 100, 80);
		//Bureaucrat	C("Leonard", 0);
		//Bureaucrat	D("Mike", 2000);

		test.beSigned(B);
		B.signForm(test);
		test.execute(B);
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
