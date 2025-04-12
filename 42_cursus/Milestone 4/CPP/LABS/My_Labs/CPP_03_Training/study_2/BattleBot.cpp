/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BattleBot.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:32:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/12 20:18:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BattleBot.hpp"

BattleBot::BattleBot(std::string name) : TinyBot(name) {}

BattleBot::~BattleBot() {}

BattleBot::BattleBot(const BattleBot &battle_robot) : TinyBot(battle_robot) {}

BattleBot& BattleBot::operator=(const BattleBot &battle_robot)
{
	if (this != &battle_robot)
	{
		this->name = battle_robot.name;
		this->energy = battle_robot.energy;
	}
	return (*this);
}

void	BattleBot::attack(const BattleBot &robot)
{
	if (this->energy <= 0)
	{
		std::cerr << "BattleRobot " << name << " doesn't have enough energy to attack" << std::endl;
		return ;
	}
	std::cout << this->get_name() << " attacks " << robot.get_name() << std::endl;
	this->energy--;
}
