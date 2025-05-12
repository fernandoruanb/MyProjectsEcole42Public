/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:28:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/12 11:20:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Robson", 10);
		Bureaucrat b;

		std::cout << a.getName() << std::endl;
		std::cout << b.getName() << std::endl;
		std::cout << "Bureaucrat A first grade: " << a.getGrade() << std::endl;
		++a;
		std::cout << "New grade: " <<  a << std::endl;
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
	return (0);
}
