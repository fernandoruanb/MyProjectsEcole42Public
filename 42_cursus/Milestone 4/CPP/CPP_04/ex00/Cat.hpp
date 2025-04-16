/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:17:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 10:25:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string type;
	public:
		Cat(void);
		Cat(std::string type);
		~Cat(void);
		Cat(const Cat &other);
		void	makeSound(void) const override;
		Cat& operator=(const Cat &other);
};
std::ostream& operator<<(std::ostream &out, const Cat &other);

#endif /* CAT_HPP */
