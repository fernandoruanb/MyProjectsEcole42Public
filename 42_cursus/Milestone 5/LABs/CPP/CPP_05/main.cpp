/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:48:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 12:15:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"

int	main(void)
{
	try
	{
	
		Student a("Thiago", 20);
		Student b;
		Student c(b);
		
		std::cout << a;
		std::cout << b;
		std::cout << c;
		b = a;
		std::cout << b;
		std::cout << "Student A Grade: " << a.getGrade() << std::endl;
		std::cout << "Student B Grade: " << b.getGrade() << std::endl;
		++a;
		++b;
		std::cout << "Student A Grade: " << a.getGrade() << std::endl;
		std::cout << "Student B Grade: " << b.getGrade() << std::endl;
		--a;
		--b;
		std::cout << "Student A Grade: " << a.getGrade() << std::endl;
		std::cout << "Student B Grade: " << b.getGrade() << std::endl;
		a++;
		b++;
		std::cout << "Student A Grade: " << a.getGrade() << std::endl;
		std::cout << "Student B Grade: " << b.getGrade() << std::endl;
		a--;
		b--;
		std::cout << "Student A Grade: " << a.getGrade() << std::endl;
		std::cout << "Student B Grade: " << b.getGrade() << std::endl;
	}
	catch (Student::GradeTooHighException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (Student::GradeTooLowException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch(std::exception &exception)
	{
		std::cerr << "Another exception" << std::endl;
	}
	return (0);
}
