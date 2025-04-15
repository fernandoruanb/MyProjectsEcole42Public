/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:25:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/15 18:40:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(std::string type);
		virtual ~Animal(void);
		virtual void makeSound(void) const = 0;
		Animal(const Animal &other);
		std::string get_Animal_name(void) const;
		Animal& operator=(const Animal &other);
};
std::ostream& operator<<(std::ostream &out, const Animal &other);
