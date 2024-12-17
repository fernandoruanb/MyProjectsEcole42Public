/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:32:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/16 21:32:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_data.current_char = g_data.current_char << 1;
	if (sig == SIGUSR2)
		g_data.current_char = g_data.current_char | 1;
	g_data.count_bits++;
	if (g_data.count_bits == 8)
	{
		if (g_data.current_char == '\0')
		{
			if (g_data.message)
			{
				printf("%s\n", g_data.message);
				free(g_data.message);
				g_data.message = NULL;
			}
		}
	}
	else
		g_data.message = append_char(g_data.message, g_data.current_char);
	g_data.current_char = 0;
	g_data.count_bit = 0;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	t_sigaction	new_connection;
	pid_t	pid;

	pid = getpid();
	if (pid < 0)
	{
		printf("Invalid PID.\n");
		return (1);
	}
	printf("Welcome to Fernando's server.\n");
	printf("You can communicate by %d PID.\n", pid);
	new_connection.sa_sigaction = handle_signal;
	new_connection.sa_flags = SA_SIGINFO;
	sigemptyset(&new_connection.sa_mask);
	sigaction(SIGUSR1, &new_connection, NULL);
	sigaction(SIGUSR2, &new_connection, NULL);
	while (1)
	{
		pause();
	}
	return (0);
