/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:52:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 18:36:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm(target, 145, 137), target(target)
{
	if (this->getRequiredGrade() < 1 || this->getRequiredExec() < 1)
		throw AForm::GradeTooHighException();
	if (this->getRequiredGrade() > 150 || this->getRequiredExec() > 150)
		throw AForm::GradeTooLowException();
	std::cout << "ShrubberyCreationForm construtor called for " << this->getTarget() << " ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called for " << this->getTarget() << " ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &another): AForm(another.getTarget(), 145, 137), target(another.getTarget())
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
	if (this->getIsSign() && executor.getGrade() <= this->getRequiredExec())
	{
		std::ofstream out((this->getTarget() + "_shrubbery").c_str());
		if (!out.is_open())
		{
			std::cerr << "Error creating the file" << std::endl;
			return ;
		}
		out <<"                                  /\\        " << std::endl;
		out <<"                                  ..         " << std::endl;
		out <<"                                ......       " << std::endl;
		out <<"                              .........    " << std::endl;
		out <<"                        ..:::::::::::::::.." << std::endl;
		out <<"                       ...:::::::::::::::..." << std::endl;
                out << "                    .:+-::::::::::::::::::-+=." << std::endl;
                 out << "                .:-=--==================--==-===:." << std::endl;
               out << "               .:-==--=============--====--=---=..." << std::endl;
             out << "             .:-===--==================----======--===:." << std::endl;
           out << "            .:===--=================-----=======--====-:." << std::endl;
         out << "           .:===--====================--============--===-:." << std::endl;
       out << "          .:====--==================--==============--====-:." << std::endl;
      out << "         -=====--====================--===========--======-:" << std::endl;
    out << "       .:=====--=======================--=========--========-:." << std::endl;
   out << "      .:===--=============================--==========--======--:." << std::endl;
  out << "      .:===--================================--========--=======--:." << std::endl;
 out << "     .:====--=================================--======--========--=:" << std::endl;
out << "    ...::::::::---::::::::----::::::::-----:::::---::::::::-----:::..." << std::endl;
                          out << "		|          |||||||||||||||      |" << std::endl;
                          out << "		O	   |||||||||||||||      O" << std::endl;
                          out << "			   |||||||||||||||" << std::endl;
                         out << "	               	   |||||||||||||||" << std::endl;
			 out << "                          /|||||||||||||||\\" << std::endl;
		out.close();
		std::cout << executor.getName() << " executed " << this->getTarget() << " Form" << std::endl;
	}
	else
		std::cerr << executor.getName() << " didn't execute ShrubberyCreationForm" << std::endl;
}

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm &another)
{
	out << "ShrubberyCreationForm Target: " << another.getTarget() << std::endl;
	return (out);
}
