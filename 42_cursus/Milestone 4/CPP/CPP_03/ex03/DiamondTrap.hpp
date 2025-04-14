/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:53:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/14 16:02:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		DiamondTrap& operator=(const DiamondTrap &other);
		DiamondTrap(const DiamondTrap &other);
		std::string	get_name(void) const;
		void	whoAmI(void);
};
std::ostream& operator<<(std::ostream &out, const DiamondTrap &other);

#endif /* DIAMONDTRAP_HPP */
