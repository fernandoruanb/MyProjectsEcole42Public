/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:25:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/18 16:34:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

class Serializer
{
	private:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer &another);
		Serializer& operator=(const Serializer &another);
};
std::ostream operator<<(std::ostream& out, const Serializer

#endif /* SERIALIZER_HPP */
