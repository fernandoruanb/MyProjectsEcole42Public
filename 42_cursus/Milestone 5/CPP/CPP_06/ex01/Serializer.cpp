/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:58:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/18 18:17:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Default constructor called" << std::endl;
}

Serializer::~Serializer(void)
{
	std::cout << "Destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &another)
{
	(void)another;
	std::cout << "Copy constructor called" << std::endl;
}

Serializer&	Serializer::operator=(const Serializer &another)
{
	(void)another;
	return (*this);
}

uintptr_t	Serializer::serialize(t_data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_data	*Serializer::deserialize(uintptr_t target)
{
	return (reinterpret_cast<t_data*>(target));
}

std::ostream& operator<<(std::ostream &out, const Serializer &another)
{
	(void)another;
	out << "It is a serializer =D" << std::endl;
	return (out);
}
