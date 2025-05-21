/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:48:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 13:31:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat A("Robert", 100);
		Bureaucrat B("Thiago", 10);
		Bureaucrat C(A);
		//Bureaucrat C("Thomas", 0);
		//Bureaucrat D("Jonathan", 1000);

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
		C = B;
		std::cout << "C: " << C << std::endl;
		C.incrementGrade();
		std::cout << "C: " << C << std::endl;
		C.decrementGrade();
		std::cout << "C: " << C << std::endl;
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
		std::cerr << "Another exception found!!!" << std::endl;
	}
	return (0);
}
