/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:21:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 09:24:36 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>

class HumanA
{
	private:
		std::string	Weapon;
		std::string	name;
	public:
		std::string	getType(void) const;
		void	setType(std::string);
};

#endif /* HUMANA_HPP */
