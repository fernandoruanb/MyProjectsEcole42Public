/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:50:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/08 11:17:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

static int	
static bool	checkPorts(std::string port)
{
	std::string	tmp;
	int	*err;
	int	result;

	tmp = port;
	while (*tmp)
	{
		if (*tmp >= '0' && *tmp <= '9')
			tmp++;
		else
		{
			std::cerr << RED "Error: Invalid Port -> " << YELLOW << port << RESET << std::endl;
			return (-1);
		}
	}
	result = atoiIRC(port, &err);
	if (err == 1)
	{
		std::cerr << RED "Error: Maximum port is 65535" RESET << std::endl;
		return (-1);
	}
	return (result);
}

int	main(int argc, char **argv)
{
	std::string	port;
	std::string	password;
	int	result;

	if (argc != 3)
	{
		std::cerr << LIGHT_BLUE "How to use: ./ircserver <port> <password>" << std::endl;
		return (1);
	}
	err = 0;
	port = argv[1];
	password = argv[2];
	result = checkPorts(port);
	if (result == -1)
		return (1);
	if (password.empty())
	{
		std::cerr << RED "You need to set a password" RESET << std::endl;
		return (1);
	}
	Server(result, password);
	return (0);
}
