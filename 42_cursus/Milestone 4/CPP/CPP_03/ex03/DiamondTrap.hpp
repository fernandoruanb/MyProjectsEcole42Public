/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:53:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/13 22:22:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap : public ClapTrap, public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap& operator=(const DiamondTrap &other);
		DiamondTrap(const DiamondTrap &other);
		std::string	get_name(void) const;
};
std::ostream& operator<<(std::ostream &out, const DiamondTrap &other);

#endif /* DIAMONDTRAP_HPP */
