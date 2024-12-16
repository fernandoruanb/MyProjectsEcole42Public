/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 08:32:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/15 18:59:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print_bits(char character);

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	mount_char(int signum)
{
	static int	index = 8;
	static unsigned char	character = 0;

	if (signum == SIGUSR1)
		character = character << 1 | 0;
	if (signum == SIGUSR2)
		character = character << 1 | 1;
	//print_bits(character);
	index--;
	if (index == 0)
	{
		//printf("Entrou aqui.\n");
		ft_putchar(character);
		index = 8;
		character = 0;
	}
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
	{
		//printf("Sinal 0 received.\n");
		mount_char(signum);
		//kill(info->si_pid, SIGUSR2);
		//write(1, "\n", 1);
	}
	else if (signum == SIGUSR2)
	{
		//printf("Sinal 1 receveid.\n");
		mount_char(signum);
		//kill(info->si_pid, SIGUSR1);
		//write(1, "\n", 1);
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
