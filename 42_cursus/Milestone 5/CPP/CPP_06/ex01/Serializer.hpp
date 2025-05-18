/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:25:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/18 18:17:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

class Serializer
{
	private:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer &another);
		Serializer& operator=(const Serializer &another);
	public:
		//static uintptr_t serialize(Data* ptr);
		//static Data* deserialize(uintptr_t raw);
};
std::ostream& operator<<(std::ostream& out, const Serializer &another);

#endif /* SERIALIZER_HPP */
