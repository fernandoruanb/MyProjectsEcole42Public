/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client_test2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 12:05:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Esse teste é para checar se o PID é tratado corretamente
 * mesmo que sejam caracteres especiais ou letras */

static void	handle_answer(int signal)
{
	if (signal == SIGUSR1)
		printf("Server signal received successfully.\n");
}

int	main(int argc, char **argv)
{
	pid_t		pid;
	t_sigaction	new_connection;

	if (argc != 3)
	{
		printf("How to use: [PID] [MESSAGE].\n");
		return (1);
	}
	pid = getpid();
	printf("The client's PID is: %d\n", pid);
	new_connection.sa_handler = handle_answer;
	new_connection.sa_flags = 0;
	sigemptyset(&new_connection.sa_mask);
	sigaction(SIGUSR1, &new_connection, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
