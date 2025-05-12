/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:18:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/12 15:09:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), target(target);
{
	std::cout << "Default constructor called for target " << target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor called for target " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
{
	std::cout << "Copy constructor called for target " << target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->target = other.getTarget();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &out, ShrubberyCreationForm& other)
{
	out << "That is the tree form" << std::endl;
	return (out);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (target);
}

void	execute_tree(const Bureaucrat &check)
{
	if (check.getGrade < 1)
		throw GradeTooHighException();
	if (check.getGrade > 150)
		throw GradeTooLowException();
	draw_ascii_tree(this->target);
}

void	draw_ascii_tree(std::string target)
{
	std::ofstream out(target + "_shrubbery");
	if (!out.is_open())
	{
		std::cerr << "Failed to open the file" << std::endl;
	}
	out << R"(
       /\
      /**\
     /****\
    /******\
   /********\
  /**********\
 /************\
/**************\
       ||
       ||
       ||
      /||\ )" << std::endl;
	out.close();
}
