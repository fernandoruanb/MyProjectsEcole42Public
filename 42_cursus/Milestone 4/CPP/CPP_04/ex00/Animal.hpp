/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:25:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/17 08:45:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	private:
		std::string type;
	public:
		Animal(void);
		Animal(std::string type);
		virtual ~Animal(void);
		virtual void makeSound(void) const = 0;
		Animal(const Animal &other);
		virtual std::string getType(void) const = 0;
		Animal& operator=(const Animal &other);
};
std::ostream& operator<<(std::ostream &out, const Animal &other);

#endif /* ANIMAL_HPP */
