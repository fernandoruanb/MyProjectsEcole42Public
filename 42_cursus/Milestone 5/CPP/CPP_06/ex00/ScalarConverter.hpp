/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:11:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/16 17:53:55 by fruan-ba         ###   ########.fr       */
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
		std::string	isInt(const std::string target) const;
		std::string	isChar(const std::string target) const;
		std::string	isFloat(const std::string target) const;
		std::string	isDouble(const std::string target) const;
};
std::ostream& operator<<(std::ostream &out, const ScalarConverter &another);

#endif /* SCALARCONVERTER_HPP */
