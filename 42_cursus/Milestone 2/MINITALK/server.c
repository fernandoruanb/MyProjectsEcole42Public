/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 08:32:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/15 08:38:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	if (signum == SIGUSR1)
		printf("Sinal 0 received.\n");
	else if (signum == SIGUSR2)
		printf("Sinal 1 receveid.\n");
}

int	main(void)
{
	t_sigaction sa;
	pid_t		pid;

	pid = getpid();
	printf("The server PID is: %d\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
