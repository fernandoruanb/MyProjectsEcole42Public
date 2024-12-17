/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_first_step.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:45:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 15:37:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minitalk.h"

static void	send_char(pid_t pid, char c);

static void	send_message(pid_t pid, const char *message)
{
	int	index;

	index = 0;
	while (message[index] != '\0')
	{
		send_char(pid, message[index]);
		index++;
	}
	send_char(pid, message[index]);
}

static void	send_char(pid_t pid, char c)
{
	int	index;
	unsigned char	character;

	index = 7;
	character = (unsigned char)c;
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

static void	handle_answer(int signal)
{
	if (signal == SIGUSR1)
		printf("The server signal was received successfully.\n");
}

static int	ft_atoi(const char *nptr)
{
	int	index;
	int	result;
	int	signal;

	index = 0;
	result = 0;
	signal = 1;
	while (nptr[index] == ' ' || nptr[index] == '\t' || nptr[index] == '\n'
		|| nptr[index] == '\r' || nptr[index] == '\f' || nptr[index] == '\v')
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
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

	if (argc != 3)
	{
		printf("How to use: ./client [PID] [MESSAGE].\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 4194304)
	{
		printf("Invalid PID.\n");
		return (1);
	}
	signal(SIGUSR1, handle_answer);
	send_message(pid, argv[2]);
	return (0);
}