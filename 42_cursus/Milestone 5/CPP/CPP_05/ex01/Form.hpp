/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 21:10:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/10 22:35:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool	is_sign;
		int	sign_grade;
		int	sign_execute;
	public:
		Form(void);
		Form(std::string name, bool is_sign, int sign_grade, sign_execute);
		Form(Form &another);
		~Form(void);
		Form& operator=(Form &other);
		Form& operator--(void);
		Form& operator++(void);
		Form operator--(int);
		Form operator++(int);
		void	beSigned(Bureaucrat &check);
		std::string	getFormName(void) const;
		bool	getIsSign(void) const;
};
std::ostream& operator<<(std::ostream &out, Form &another);

#endif /* FORM_HPP */
