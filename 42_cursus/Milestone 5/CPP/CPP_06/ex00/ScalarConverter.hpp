/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:11:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/16 18:27:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <climits>

class	ScalarConverter
{
	public:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &another);
		ScalarConverter& operator=(const ScalarConverter &another);
		std::string	isInt(std::string target) const;
		std::string	isChar(std::string target) const;
		std::string	isFloat(std::string target) const;
		std::string	isDouble(std::string target) const;
};
std::ostream& operator<<(std::ostream &out, const ScalarConverter &another);

#endif /* SCALARCONVERTER_HPP */
