/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:21:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 10:06:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>

class HumanA
{
	private:
		Weapon		weapon;
		std::string	type;
		std::string	name;
	public:
		HumanA(std::string name, Weapon);
		~HumanA();
};

#endif /* HUMANA_HPP */
