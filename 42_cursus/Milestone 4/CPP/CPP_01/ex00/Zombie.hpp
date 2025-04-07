/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:23:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 09:28:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		static Zombie*	newZombie(std::string name);
		static void	randomChump(std::string name);
};

#endif /* ZOMBIE_HPP */
