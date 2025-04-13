/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serena.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:30:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/13 14:43:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERENA_HPP
# define SERENA_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);
		void	guardGate(void);
		std::string	get_name(void) const;
};
std::ostream& operator<<(std::ostream &out, const ScavTrap &other);

#endif /* SERENA_HPP */
