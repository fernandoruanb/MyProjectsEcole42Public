/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:14:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/09 17:24:25 by fruan-ba         ###   ########.fr       */
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
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &another);
		float	toFloat(void) const;
		int	toInt(void) const;
};
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif /* FIXED_HPP */
