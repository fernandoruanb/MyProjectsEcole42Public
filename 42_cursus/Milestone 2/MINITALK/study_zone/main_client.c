/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:34:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 11:46:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_sigaction	new_connection;
	pid_t		pid;

	if (argc != 3)
	{
		printf("How to use: [PID] [MESSAGE].\n");
		return (1);
	}
	pid = atoi(argv[1]);
	if (pid <= 0 || pid > 4194304)
	{
		printf("Invalid PID.\n");
		return (1);
	}
	printf("The PID: %d\n", pid);
	printf("The client's message: %s\n", argv[2]);
	new_connection.sa_handler = handle_answer;
	new_connection.sa_flags = 0;
	sigemptyset(&new_connection.sa_mask);
	sigaction(SIGUSR1, &new_connection, NULL);
	return (0);
}
