/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:59:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 15:44:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int	hit_points;
		unsigned int	energy;
		unsigned int	attack_damage;
	public:
		ClapTrap(std::string name);
		ClapTrap(void);
		~ClapTrap(void);
		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		std::string     get_name(void) const;
                unsigned int    get_hit_points(void) const;
                unsigned int    get_energy(void) const;
                unsigned int    get_attack_damage(void) const;
		int	get_status(void) const;
		std::string get_clapTrap(void) const;
};
std::ostream& operator<<(std::ostream &out, const ClapTrap &other);

#endif /* CLAPTRAP_HPP */
