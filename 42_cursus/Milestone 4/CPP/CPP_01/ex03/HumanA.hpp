/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:21:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/08 17:23:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	private:
		Weapon		&weapon;
		std::string	type;
		std::string	name;
	public:
		void	attack(void) const;
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
};

#endif /* HUMANA_HPP */
