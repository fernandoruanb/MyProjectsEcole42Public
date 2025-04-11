/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:25:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/11 14:38:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hello_World.hpp"

int	main(int argc, char **argv)
{
	Message	MyMessage;

	if (argc != 2)
		return (1);
	MyMessage.set_message(argv[2]);
	MyMessage.get_message();
	return (0);
}
