/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:07:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 11:28:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>

class WrongCat : public WrongAnimal
{
	private:
		std::string type;
	public:
		WrongCat(void);
		WrongCat(std::string type);
		~WrongCat(void);
		WrongCat(const &WrongCat &other);
		void	makeSound(void) const override;
		std::string get_WrongCat_type(void) const;
		WrongCat& operator=(const WrongCat &other);
};
std::ostream& operator<<(std::ostream &out, const WrongCat &other);

#endif /* WRONGCAT_HPP */
