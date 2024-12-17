/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:35:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 10:40:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	handle_answer(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;

	if (signal == SIGUSR2)
		printf("Server answer received sucessfully.\n");
}

static void	send_char(pid_t pid, char c)
{
	int	index;
	unsigned char	character;

	character = (unsigned char)c;
	index = 7;
	while (index >= 0)
	{
		if (character >> index & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		index--;
	}
}

static void	send_message(pid_t pid, const char *message)
{
	int	index;

	index = 0;
	while (message[index] != '\0')
	{
		send_char(pid, message[index]);
		index++;
	}
	send_char(pid, '\0');
}

static int	ft_atoi(const char *nptr)
{
	int	index;
	int	result;
	int	signal;

	index = 0;
	result = 0;
	signal = 1;
	while (nptr[index] == ' ' || nptr[index] == '\t' || nptr[index] == '\v'
		|| nptr[index] == '\r' || nptr[index] == '\f' || nptr[index] == '\n')
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			signal = -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result *= 10;
		result += (nptr[index] - '0');
		index++;
	}
	return (result * signal);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	t_sigaction	new_connection;

	if (argc != 3)
	{
		printf("How to use: [PID] [MESSAGE].\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		printf("Invalid PID.\n");
		return (1);
	}
	new_connection.sa_handler = handle_answer;
	new_connection.sa_flags = 0;
	sigemptyset(&new_connection.sa_mask);
	sigaction(SIGUSR1, &new_connection, NULL);
	send_message(pid, argv[2]);
	return (0);
}
