/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 08:32:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/16 15:26:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print_bits(char character);

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	mount_char(int signum)
{
	static int	index = 8;
	static unsigned char	character = 0;

	if (signum == SIGUSR1)
		character = character << 1 | 0;
	if (signum == SIGUSR2)
		character = character << 1 | 1;
	index--;
	print_bits(character);
	if (index == 0)
	{
		ft_putchar(character);
		index = 8;
		character = 0;
	}
	return (1);
	write(1, "\n", 1);
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	(void)context;
	kill(info->si_pid, SIGUSR2);
	printf("Enviou sinal de 0 para ready\n");
	if (signum == SIGUSR1)
	{
		printf("Receveid Sinal 0.\n");
		mount_char(signum);
		kill(info->si_pid, SIGUSR1);
		printf("Envio sinal de 1 para ready\n");
	}
	else if (signum == SIGUSR2)
	{
		printf("Receveid Sinal 1.\n");
		mount_char(signum);
		kill(info->si_pid, SIGUSR1);
		printf("Envio sinal de 1 para ready.\n");
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
