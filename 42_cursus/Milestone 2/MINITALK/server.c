/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 08:32:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/16 11:04:36 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_bits(char character);

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	mount_char(int signum)
{
	static int	connections = 0;
	static int	index = 8;
	static unsigned char	character = 0;

	if (connections == 0)
		connections++;
	if (signum == SIGUSR1 && connections > 0)
		character = character << 1 | 0;
	if (signum == SIGUSR2 && connections > 0)
		character = character << 1 | 1;
	if (connections > 0)
		index--;
	print_bits(character);
	if (index == 0)
	{
		ft_putchar(character);
		index = 8;
		character = 0;
	}
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
	{
		printf("Received signal 0.\n");
		mount_char(signum);
		kill(info->si_pid, SIGUSR2);
	}
	else if (signum == SIGUSR2)
	{
		printf("Received signal 1.\n");
		mount_char(signum);
		kill(info->si_pid, SIGUSR2);
	}
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
