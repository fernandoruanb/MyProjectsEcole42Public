/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:59:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/21 16:13:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
//Basic colours
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

//Bright colours
# define BRIGHT_BLACK "\033[1;30m"
# define BRIGHT_RED "\033[1;31m"
# define BRIGHT_GREEN "\033[1;32m"
# define BRIGHT_YELLOW "\033[1;33m"
# define BRIGHT_BLUE "\033[1;34m"
# define BRIGHT_MAGENTA "\033[1;35m"
# define BRIGHT_CYAN "\033[1;36m"
# define BRIGHT_WHITE "\033[1;37m"

//256 colours
# define GREY "\033[38;5;8m"
# define DARK_GREY "\033[38;5;235m"
# define LIGHT_GREY "\033[38;5;250m"
# define LIGHT_BLUE "\033[38;5;33m"
# define LIGHT_GREEN "\033[38;5;82m"
# define LIGHT_YELLOW "\033[38;5;220m"
# define LIGHT_RED "\033[38;5;196m"
# define LIGHT_MAGENTA "\033[38;5;201m"
# define LIGHT_CYAN "\033[38;5;14m"

//Background colours
# define BG_BLACK "\033[48;5;0m"
# define BG_RED "\033[48;5;1m"
# define BG_GREEN "\033[48;5;2m"
# define BG_YELLOW "\033[48;5;3m"
# define BG_BLUE "\033[48;5;4m"
# define BG_MAGENTA "\033[48;5;5m"
# define BG_CYAN "\033[48;5;6m"
# define BG_WHITE "\033[48;5;7m"

//Reset
# define RESET "\033[0m"
# include <iostream>

class ClapTrap
{
	private:
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
		std::string	get_name(void) const;
		unsigned int	get_hit_points(void) const;
		unsigned int	get_energy(void) const;
		unsigned int	get_attack_damage(void) const;
		int	get_status(void) const;
		std::string get_clapTrap(void) const;
};
std::ostream& operator<<(std::ostream &out, const ClapTrap &other);

#endif /* CLAPTRAP_HPP */
