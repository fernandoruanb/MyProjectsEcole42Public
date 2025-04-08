/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:33:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 17:24:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
	private:
		Weapon*	weapon;
		std::string	type;
		std::string	name;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon* weapon);
		void	attack(void) const;
};

#endif /* HUMANB_HPP */
