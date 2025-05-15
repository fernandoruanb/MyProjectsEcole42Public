/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:39:19 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/15 11:47:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm
{
	private:
		const std::string	target;
	public:
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &another);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& another);
		std::string	getTarget(void) const;
		void	beSigned(const Bureaucrat &attempt);
		void	execute(Bureaucrat const & executor) const;
};
std::ostream& operator<<(std::ostream &out, const PresidentialPardonForm &another);

#endif /* PRESIDENTIALPARDONFORM_HPP */
