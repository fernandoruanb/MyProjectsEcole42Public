/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internet.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:45:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/04 21:49:37 by fruan-ba         ###   ########.fr       */
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
	int	result;
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
	result = atoiIRC(argv[1], &err);
	if (err == 1)
	{
		std::cerr << BRIGHT_RED "Error: Maximum port is 65535" RESET << std::endl;
		return (0);
	}
	return (result);
}

static void	handleSignal(int signal)
{
	t_server	*ircserver = getServer();

	if (signal == SIGINT)
	{
		std::cout << ORANGE "Recebi SIGINT" RESET << std::endl;
		ircserver->running = false;
		close(ircserver->serverIRC);
	}
}

int	main(int argc, char **argv)
{
	t_server	*ircserver;
	int	result;

	ircserver = getServer();
	ircserver->serverIRC = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	fcntl(ircserver->serverIRC, F_SETFL, O_NONBLOCK);
	signal(SIGINT, handleSignal);
	if (ircserver->serverIRC == -1)
	{
		std::cerr << "Error: socket didn't start" << std::endl;
		return (1);
	}
	result = checkArguments(argc, argv);
	if (result == 0)
	{
		close(ircserver->serverIRC);
		return (1);
	}
	ircserver->opt = 1;
	ircserver->server.sin_family = AF_INET;
	ircserver->server.sin_port = htons(result);
	ircserver->server.sin_addr.s_addr = inet_addr("127.0.0.1");

	setsockopt(ircserver->serverIRC, SOL_SOCKET, SO_REUSEADDR, &ircserver->opt, sizeof(ircserver->opt));
	ircserver->client_len = sizeof(ircserver->client);

	if (bind(ircserver->serverIRC, (struct sockaddr *)&ircserver->server, sizeof(ircserver->server)) == 0)
	{
		std::cout << BRIGHT_GREEN "Bind successfully on " BRIGHT_YELLOW "127.0.0.1:" << argv[1] << RESET << std::endl;
		ircserver->running = true;
		if (ircserver->running && listen(ircserver->serverIRC, 10) == 0)
		{
			std::cout << LIGHT_BLUE "Listen Mode Started =D" RESET << std::endl;
			ircserver->clFD = accept(ircserver->serverIRC, (struct sockaddr *)&ircserver->client, &ircserver->client_len);
			if (ircserver->clFD != -1)
				fcntl(ircserver->clFD, F_SETFL, O_NONBLOCK);
			pause();
			if (ircserver->running)
				close(ircserver->clFD);
		}
		else
		{
			std::cout << BRIGHT_RED "Listen Mode Failed D=" RESET << std::endl;
			if (ircserver->running)
				close(ircserver->serverIRC);
			return (1);
		}
	}
	else
	{
		std::cerr << BRIGHT_RED "Error: Bind crash" RESET << std::endl;
		if (ircserver->running)
			close(ircserver->serverIRC);
		return (1);
	}
	std::cout << BRIGHT_GREEN "Thank you very much for using our IRC Server =D" RESET << std::endl;
	if (ircserver->running)
		close(ircserver->serverIRC);
	return (0);
}
