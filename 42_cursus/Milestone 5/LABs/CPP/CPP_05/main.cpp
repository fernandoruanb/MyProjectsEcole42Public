/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:48:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 11:52:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"

int	main(void)
{
	try
	{
	
		Student a("Thiago", 20);
		Student b;
		std::cout << a;
		std::cout << b;
	}
	catch (Student::GradeTooHighException &exception)
	{
		std::cerr << exception.what();
	}
	catch (Student::GradeTooLowException &exception)
	{
		std::cerr << exception.what();
	}
	catch(std::exception &exception)
	{
		std::cerr << "Another exception" << std::endl;
	}
	return (0);
}
