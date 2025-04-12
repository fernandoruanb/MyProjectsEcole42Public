/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:24:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/12 17:40:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tinybot.hpp"

int	main(int argc, char **argv)
{
	TinyBot	MyLittleBot("Bob");

	MyLittleBot.announce();
	MyLittleBot.show_status();
	MyLittleBot.recharge_energy();
	MyLittleBot.show_status();
	std::cout << MyLittleBot << std::endl;
	return (0);
}
