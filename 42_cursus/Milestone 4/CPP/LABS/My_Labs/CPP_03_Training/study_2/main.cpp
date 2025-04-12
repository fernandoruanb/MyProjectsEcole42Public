/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:11:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/12 20:12:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TinyBot.hpp"
#include "BattleBot.hpp"

int	main(void)
{
	TinyBot MyLittleBot("Bob");
	BattleBot MyBattleBot("powerful_bob");
	BattleBot YourBattleBot("powerful_jedi");

	MyLittleBot.announce();
	MyLittleBot.show_status();
	MyLittleBot.recharge_energy();
	MyLittleBot.show_status();
	MyBattleBot.announce();
	MyBattleBot.show_status();
	MyLittleBot.recharge_energy();
	YourBattleBot.announce();
	YourBattleBot.show_status();
	YourBattleBot.recharge_energy();
	MyBattleBot.attack(YourBattleBot);
	YourBattleBot.attack(MyBattleBot);
	MyBattleBot.show_status();
	YourBattleBot.show_status();
	MyBattleBot.attack(YourBattleBot);
	MyBattleBot.attack(YourBattleBot);
	MyBattleBot.attack(YourBattleBot);
	MyBattleBot.attack(YourBattleBot);
	MyBattleBot.attack(YourBattleBot);
	YourBattleBot.attack(MyBattleBot);
	YourBattleBot.attack(MyBattleBot);
	YourBattleBot.attack(MyBattleBot);
	YourBattleBot.attack(MyBattleBot);
	YourBattleBot.attack(MyBattleBot);
	MyBattleBot.show_status();
        YourBattleBot.show_status();
	return (0);
}
