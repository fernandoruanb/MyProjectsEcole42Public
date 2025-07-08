/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:02:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/07/08 12:03:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internet.hpp"

Server::Server(void)
{
	std::cout << LIGHT_BLUE "Starting the server with default configuration 127.0.0.1:6667" RESET << std::endl;
	init(6667, "password");
}

Server::~Server(void)
{
	std::cout << BRIGHT_GREEN "Thank you very much for using our IRC Server =D" RESET << std::endl;
}

Server::Server(std::string port, int *err)
{
	std::string	tmp;

	while (*tmp)
	{
		if (*tmp >= '0' && *tmp <= '9')
			tmp++;
		else
		{

		}
	}
}

Server::atoiIRC(std::string port)
{
	std::string	tmp;
	int	result;

	tmp = port;
	result = 0;

	if (port.empty())
		return (-1);
	while (*tmp >= '0' && *tmp <= '9')
	{
		result *= 10;
		result += *tmp - '0';
		if (result > 65535)
			return (-1);
		tmp++;
	}
	if (*tmp != '\0')
		return (-1);
	return (result);
}

Server::Server(std::string portCheck, std::string password)
{
	int	port;

	try
	{
		port = atoiIRC(portCheck);
		if (port == -1)
			throw std::exception();
		if (password.empty())
			throw std::exception();
		std::cout << LIGHT_BLUE "Starting the server with your configuration 127.0.0.1:" << YELLOW <<  port << RESET << std::endl;
		init(port, password);

	} catch (std::exception &e) 
	{
		std::cerr << "Error: Invalid configuration (Port/Password) -> " << YELLOW << port << password << RESET << std::endl;
	}
}

Server::init(int port, std::string password)
{
	this->setPassword(password);
	this->setPort(port);

	try {
		sockaddr_t	server;

		serverIRC = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (serverIRC == -1)
			throw std::exception();

		this->setServerIRC(serverIRC);

		server.sin_family = AF_INET;
		server.sin_port = port;
		server.sin_addr.s_addr = inet_addr("127.0.0.1");

		if (bind(serverIRC, (struct sockaddr *)&server, sizeof(server)) == 0)
		{
			std::cout << BRIGHT_GREEN "Bind successfully!!!" << RESET << std::endl;
			if (listen(serverIRC, 1024) == 0)
			{
				std::cout << BRIGHT_GREEN "The server is listening on " << YELLOW << "127.0.0.1:" << port << RESET << std::endl;
				this->setIsRunning(true);
				//this->startIRCService();
			}
			else
			{
				std::cerr << "Error: The server can't listen anything" << std::endl;
				throw std::exception();
			}
		}
		else
		{
			std::cerr << RED "Error: Bind failed" RESET << std::endl;
			throw std::exception();
		}
	} catch (std::exception &e) {}
}
