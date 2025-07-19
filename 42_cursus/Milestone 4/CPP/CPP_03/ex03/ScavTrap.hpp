/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:56:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/19 16:38:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);
		void	guardGate(void);
		int     getHitPoints(void) const;
		void	attack(const std::string &target);
		std::string	get_name(void) const;
		int	get_hit_points(void) const;
};
std::ostream& operator<<(std::ostream &out, const ScavTrap &other);

#endif /* SCAVTRAP_HPP */
