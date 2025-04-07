/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:33:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 10:12:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB
{
	private:
		Weapon	weapon;
		std::string	type;
		std::string	name;
	public:
		HumanB(name);
		~HumanB();
};

#endif /* HUMANB_HPP */
