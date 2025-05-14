/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:52:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/14 19:46:03 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target, int required_grade, int required_exec): target(target),
	required_grade(required_grade), required_exec(required_exec), AForm(target, required_grade, required_exec)
{
	if (required_grade < 1 || required_exec < 1)
		throw AForm::GradeTooHighException();
	if (required_grade > 150 || required_exec > 150)
		throw AForm::GradeTooLowException();
	std::cout << "ShrubberyCreationForm construtor called for " << this->getTarget() << " ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called for " << this->getTarget() << " ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &another)
{
	std::cout << "Copy constructor called for " << this->getTarget() << " ShrubberyCreationForm" << std::endl;
	this->target = another.getTarget();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &another)
{
	if (this != &another)
	{
		this->target = another.getTarget();
	}
	return (*this);
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat &attempt)
{
	if (attempt.getGrade() <= this->getRequiredGrade())
		
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getRequiredExec())
	{
		std::ofstream out(this->getTarget() + "_shrubbery");
		if (!out.is_open())
		{
			std::cerr << "Error creating the file" << std::endl;
			return ;
		}
		out << "...:::::::::::::::..." << std::endl;
                out << ".:+-::::::::::::::::::-+=." << std::endl;
                 out << ".:-=--==================--==-===:." << std::endl;
               out << ".:-==--=====================--====--=--=." << std::endl;
             out << ".:-===--========================--======--===:." << std::endl;
           out << ".:===--==========================----=======--====-:." << std::endl;
         out << ".:===--============================--============--===-:." << std::endl;
       out << ".:====--==============================--==============--====-:." << std::endl;
      out << "-=====--================================--==============--======-:" << std::endl;
    out << ".:=====--==================================--============--========-:." << std::endl;
   out << ".:======--===================================--==========--=========--:." << std::endl;
  out << ".:=======--====================================--========--==========--:." << std::endl;
 out << ".:========--=====================================--======--===========--=:" << std::endl;
out << "...::::::::---::::::::::----::::::::::-----::::::::---:::::::::::-----:::..." << std::endl;
                          out << "|||||||||||||||" << std::endl;
                          out << "|||||||||||||||" << std::endl;
                          out << "|||||||||||||||" << std::endl;
                         out << "/|||||||||||||||\\" << std::endl << std::endl;
		out.close();
	}
}

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &another)
{
	out << "ShrubberyCreationForm Target: " << another.getTarget() << std::endl;
	return (out);
}
