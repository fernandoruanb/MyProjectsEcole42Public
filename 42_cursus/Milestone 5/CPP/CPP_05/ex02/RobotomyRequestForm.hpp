/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:57:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 10:41:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm
{
	private:
		const std::string target;
	public:
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &another);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &another);
		void	beSigned(const Bureaucrat &attempt);
		void	execute(Bureaucrat const & executor) const;
		std::string	getTarget(void) const;
};
std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm &another);

#endif /* ROBOTOMYREQUESTFORM_HPP */
