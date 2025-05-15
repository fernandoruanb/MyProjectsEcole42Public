/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:48:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/13 19:13:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"
#include "AExam.hpp"
#include "MathExam.hpp"

int	main(void)
{
	try
	{
	
		Student a("Thiago", 20);
		MathExam examshell(100, 70);
		Student b;
		Student c(b);
	
		examshell.evaluate_student(a);
		examshell.execute_action(a);	
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
	catch (AExam::AExamNotPassed &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (AExam::AExamImpossibleExtra &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (MathExam::MathGradeTooHighException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (MathExam::MathGradeTooLowException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch(std::exception &exception)
	{
		std::cerr << "Another exception" << std::endl;
	}
	return (0);
}
