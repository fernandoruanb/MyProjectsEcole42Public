/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:22:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/10 11:00:27 by fruan-ba         ###   ########.fr       */
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
		int	toInt(void) const;
		float	toFloat(void) const;
};
std::ostream &operator<<(std::ostream& out, const Fixed& other);
int	&operator+(const Fixed &first, const Fixed &second);
int	&operator-(const Fixed &first, const Fixed &second);
int	&operator*(const Fixed &first, const Fixed &second);
int	&operator/(const Fixed &first, const Fixed &second);
/*int	&operator++();
int	&operator++(int number);
int	&operator<(const Fixed &first, const Fixed &second);
int	&operator>(const Fixed &first, const Fixed &second);
int	&operator**(const Fixed &first, const Fixed &second);*/

#endif /* FIXED_HPP */
