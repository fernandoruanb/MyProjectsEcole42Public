/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:51:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 12:14:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string type;
	public:
		Dog(void);
		Dog(std::string type);
		~Dog(void);
		Dog(const Dog &other);
		std::string get_dog_type(void) const;
		void	makeSound(void) const;
		Dog& operator=(const Dog &other);
};
std::ostream& operator<<(std::ostream &out, const Dog &other);

#endif /* DOG_HPP */
