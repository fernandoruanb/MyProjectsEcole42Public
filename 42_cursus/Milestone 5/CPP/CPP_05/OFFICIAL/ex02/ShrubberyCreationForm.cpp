/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:52:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/14 21:41:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target, int required_grade, int required_exec): AForm(target, required_grade, required_exec), target(target)
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &another): AForm(another.getTarget(), another.getRequiredGrade(), another.getRequiredExec()), target(another.getTarget())
{
	std::cout << "Copy constructor called for " << this->getTarget() << " ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &another)
{
	(void)another;
	return (*this);
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat &attempt)
{
	if (attempt.getGrade() <= this->getRequiredGrade())
		setSign(true);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getRequiredExec())
	{
		std::ofstream out((this->getTarget() + "_shrubbery").c_str());
		if (!out.is_open())
		{
			std::cerr << "Error creating the file" << std::endl;
			return ;
		}
		out <<"                  ...:::::::::::::::..." << std::endl;
                out << "               .:+-::::::::::::::::::-+=." << std::endl;
                 out << "             .:-=--==================--==-===:." << std::endl;
               out << "            .:-==--=====================--====--=--=." << std::endl;
             out << "           .:-===--========================--======--===:." << std::endl;
           out << "        .:===--==========================----=======--====-:." << std::endl;
         out << "       .:===--============================--============--===-:." << std::endl;
       out << "       .:====--==============================--==============--====-:." << std::endl;
      out << "      -=====--================================--==============--======-:" << std::endl;
    out << "     .:=====--==================================--============--========-:." << std::endl;
   out << "   .:======--===================================--==========--=========--:." << std::endl;
  out << "  .:=======--====================================--========--==========--:." << std::endl;
 out << " .:========--=====================================--======--===========--=:" << std::endl;
out << "...::::::::---::::::::::----::::::::::-----::::::::---:::::::::::-----:::..." << std::endl;
                          out << "			|||||||||||||||" << std::endl;
                          out << "			|||||||||||||||" << std::endl;
                          out << "			|||||||||||||||" << std::endl;
                         out << "			/|||||||||||||||\\" << std::endl << std::endl;
		out.close();
	}
}

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &another)
{
	out << "ShrubberyCreationForm Target: " << another.getTarget() << std::endl;
	return (out);
}
