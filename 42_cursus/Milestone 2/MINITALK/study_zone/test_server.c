/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:46:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 12:52:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;

	if (signal == SIGUSR1)
		mount_char(signal);
	else if (signal == SIGUSR2)
		mount_char(signal);
}

int	main(void)
{
	pid_t	pid;
	t_sigaction	new_connection;

	pid = getpid();
	printf("Welcome to Fernando's server.\n");
	printf("You can communicate by this PID: %d\n", pid);
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
}
