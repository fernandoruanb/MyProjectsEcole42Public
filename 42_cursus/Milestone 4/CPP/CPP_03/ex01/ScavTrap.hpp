/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:56:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/16 09:21:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);
		void	guardGate(void);
		void	attack(const std::string &target);
		std::string	get_name(void) const;
};
std::ostream& operator<<(std::ostream &out, const ScavTrap &other);

#endif /* SCAVTRAP_HPP */
