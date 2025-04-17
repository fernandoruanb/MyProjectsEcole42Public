/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:17:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/17 09:22:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string type;
		Brain* brain;
	public:
		Cat(void);
		Cat(std::string type);
		~Cat(void);
		Cat(const Cat &other);
		Brain& get_cat_brain(void) const;
		std::string getType(void) const;
		void	makeSound(void) const;
		Cat& operator=(const Cat &other);
};
std::ostream& operator<<(std::ostream &out, const Cat &other);

#endif /* CAT_HPP */
