/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:39:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/20 11:56:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <cfloat>
# include <cstdlib>
# include <cerrno>
# include <climits>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &another);
		ScalarConverter& operator=(const ScalarConverter &another);
		static bool	isPseudo(const std::string &target);
		static bool	isChar(const std::string &target);
		static bool	isInt(const std::string &target);
		static bool	isFloat(const std::string &target);
		static bool	isDouble(const std::string &target);
	public:
		static void converter(const std::string &target);
};
std::ostream& operator<<(std::ostream &out, const ScalarConverter &another);

#endif /* SCALARCONVERTER_HPP */
