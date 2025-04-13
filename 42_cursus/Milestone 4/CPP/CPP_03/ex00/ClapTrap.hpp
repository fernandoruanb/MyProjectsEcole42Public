/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:59:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/12 21:47:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap
{
	private:
		int	hit_points;
		int	energy;
		int	attack_damage;
	public:
		Claptrap();
		~Claptrap();
		Claptrap(const Claptrap &other);
		Claptrap& operator=(const Claptrap &other);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		std::string	get_status(void) const;
};
std::ostream& operator<<(std::ostream &out, const ClapTrap &other);

#endif /* CLAPTRAP_HPP */
