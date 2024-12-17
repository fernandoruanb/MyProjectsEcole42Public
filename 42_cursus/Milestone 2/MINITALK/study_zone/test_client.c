/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:28:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 13:32:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ready_to_send = 0;

/*static void	send_message(pid_t pid, const char *message)
{
	int	index;

	index = 0;
	while (message[index] != '\0')
	{
		send_char(pid, message[index]);
		index++;
	}
	send_char(pid, '\0');
}*/

static void	send_char(pid_t pid, char c)
{
	int	index;
	unsigned char	character;

	character = (unsigned char)c;
	index = 7;
	while (index >= 7)
	{
		if (character >> index & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		index--;
	}
}

static void	handle_answer(int signal)
{
	if (signal == SIGUSR1)
		printf("Server signal receiveid with success.\n");
}

int	ft_atoi(const char *nptr)
{
	int	index;
	int	signal;
	int	result;

	index = 0;
	result = 0;
	signal = 1;
	while (nptr[index] == ' ' || nptr[index] == '\t' || nptr[index] == '\f'
		|| nptr[index] == '\v' || nptr[index] == '\r' || nptr[index] == '\n')
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
	t_sigaction	new_connection;

	if (argc != 3)
	{
		printf("How to use: [PID] [MESSAGE].\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 4194304)
	{
		printf("Invalid PID.\n");
		return (1);
	}
	new_connection.sa_handler = handle_answer;
	new_connection.sa_flags = 0;
	sigemptyset(&new_connection.sa_mask);
	sigaction(SIGUSR1, &new_connection, NULL);
	send_char(pid, argv[1][0]);
	return (0);
}
