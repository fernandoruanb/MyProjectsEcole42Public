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

class Fixed
{
	private:
		const int	num;
		static const int	bits = 0;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &another);
		int	toFloat(void) const;
		int	toInt(void) const;
};

#endif /* FIXED_HPP */
