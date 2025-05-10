/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:28:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/10 19:18:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Robson", 3);
		Bureaucrat b;

		std::cout << a.getName() << std::endl;
		std::cout << b.getName() << std::endl;
		std::cout << a.getGrade() << std::endl;
		std::cout << b.getGrade() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		std::cerr << "Grade is too low" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << "Grade is too high" << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cerr << "There is other exception from exceptions" << std::endl;
	}
	return (0);
}
