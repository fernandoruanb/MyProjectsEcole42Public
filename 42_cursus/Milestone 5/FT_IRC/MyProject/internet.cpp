/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internet.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:45:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/04 18:15:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internet.hpp"

static int	checkPort(char *port)
{
	char	*temp;

	if (!port || !*port)
		return (0);
	temp = port;
	while (*temp)
	{
		if (*temp >= '0' && *temp <= '9')
			temp++;
		else
			return (0);
	}
	return (1);
}

static int	checkArguments(int argc, char **argv)
{
	std::string	password;
	int	err;

	if (argc != 3)
	{
		std::cerr << LIGHT_BLUE "How to use: ./ircserver <port> <password>" RESET << std::endl;
		return (0);
	}
	else if (!checkPort(argv[1]))
	{
		std::cerr << BRIGHT_RED "Error: Invalid Port " << BRIGHT_YELLOW << argv[1] << RESET << std::endl;
		return (0);
	}
	password = argv[2];
	if (password.empty())
	{
		std::cerr << BRIGHT_RED "Error: You need to set a password" RESET << std::endl;
		return (0);
	}
	err = 0;
	atoiIRC(argv[1], &err);
	if (err == 1)
	{
		std::cerr << BRIGHT_RED "Error: Maximum port is 65535" RESET << std::endl;
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	serverIRC = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	if (serverIRC == -1)
	{
		std::cerr << "Error: socket didn't start" << std::endl;
		return (1);
	}
	if (!checkArguments(argc, argv))
	{
		close(serverIRC);
		return (1);
	}
	std::cout << BRIGHT_GREEN "Thank you very much for using our IRC Server =D" RESET << std::endl;
	close(serverIRC);
	return (0);
}
