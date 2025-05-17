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
	private:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		static bool isPseudo(const std::string& target);
		static bool isChar(const std::string& target);
		static bool isInt(const std::string& target);
		static bool isFloat(const std::string& target);
		static bool isDouble(const std::string& target);
	public:
		static void	converter(const std::string& target);
};
std::ostream& operator<<(std::ostream &out, const ScalarConverter &another);

#endif /* SCALARCONVERTER_HPP */
