/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BattleBot.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:23:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/12 20:18:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BATTLEBOT_HPP
# define BATTLEBOT_HPP

# include "TinyBot.hpp"
# include <iostream>

class BattleBot : public TinyBot
{
	public:
		BattleBot(std::string name);
		~BattleBot();
		BattleBot(const BattleBot &battle_robot);
		BattleBot& operator=(const BattleBot &battle_robot);
		void attack(const BattleBot &robot);
};
std::ostream& operator<<(std::ostream &out, const BattleBot &battle_robot);

#endif /* BATTLEBOT_HPP */
