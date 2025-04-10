/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:22:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/10 14:07:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	number;
		static const int	bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int n);
		Fixed(const float num);
		Fixed &operator=(const Fixed &other);
		Fixed	operator+(const Fixed &second) const;
		Fixed	operator-(const Fixed &second) const;
		Fixed	operator*(const Fixed &second) const;
		Fixed	operator/(const Fixed &second) const;
		bool	operator<(const Fixed &second) const;
		bool	operator>(const Fixed &second) const;
		bool	operator>=(const Fixed &second) const;
		bool	operator<=(const Fixed &second) const;
		bool	operator!=(const Fixed &second) const;
		bool	operator==(const Fixed &second) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		static int	max(const Fixed &first, const Fixed &second);
		static int	max(Fixed &first, Fixed &second);
		static int	min(const Fixed &first, const Fixed &second);
		static int	min(const Fixed &first, Fixed &second);
		int	toInt(void) const;
		float	toFloat(void) const;
};
std::ostream &operator<<(std::ostream& out, const Fixed& other);

#endif /* FIXED_HPP */
