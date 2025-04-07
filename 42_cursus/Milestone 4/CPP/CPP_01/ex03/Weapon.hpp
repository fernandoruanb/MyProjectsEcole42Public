/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:06:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 10:17:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		void	setType(std::string type);
		const std::string& getType(void) const;
};

#endif /* WEAPON_HPP */
