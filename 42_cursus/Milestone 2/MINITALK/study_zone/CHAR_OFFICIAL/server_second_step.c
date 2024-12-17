/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_second_step.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:52:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 16:34:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minitalk.h"

static t_data g_data = {0, 0};

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	handle_signal(int signal, siginfo_t *info, void *context)
{
	g_data.character = g_data.character << 1; // Move para a esquerda, trata zero automaticamente
	if (signal == SIGUSR2)
	{
		g_data.character |= 1;	// Para acrescentar o binário um corretamente
	}
	g_data.bit_count++; // Incrementa a quantidade de bits.
	if (g_data.bit_count >= 8)
	{
		//printf("%c\n", g_data.character);
		ft_putchar(g_data.character);
		//printf("Bits received: %d\n", g_data.bit_count);
		g_data.character = 0;
		g_data.bit_count = 0;
	}
	usleep(900);
	kill(info->si_pid, SIGUSR1);
}
int	main(void)
{
	pid_t	pid;
	t_sigaction	new_connection;

	pid = getpid();
	printf("The server PID is: %d\n", pid); // Aqui estamos pegando o PID do servidor
	new_connection.sa_sigaction = handle_signal;
	new_connection.sa_flags = SA_SIGINFO;
	sigemptyset(&new_connection.sa_mask);
	sigaction(SIGUSR1, &new_connection, NULL);
	sigaction(SIGUSR2, &new_connection, NULL);
	while (1) // Nessa etapa, estamos colocando em loop infinito, para que o servidor continue rodando e recebendo sinais do client
	{
		pause();
	}
	return (0);
}
