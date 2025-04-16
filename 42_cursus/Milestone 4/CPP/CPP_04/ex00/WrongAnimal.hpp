/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:26:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 11:06:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	private:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		~WrongAnimal(void);
		void	makeSound(void) const = 0;
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal& operator=(const WrongAnimal &other);
};
std::ostream& operator<<(std::ostream &out, const WrongAnimal &other);
