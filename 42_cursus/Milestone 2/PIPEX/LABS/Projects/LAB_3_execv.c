/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LAB_3_execv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:34:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/23 15:28:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

static void	child_process(char **command)
{
	if (execve(command[1], command + 1, NULL) == -1)
	{
		printf("Failed to execute a command.\n");
		return ;
	}
}

int	main(int argc, char **argv)
{
	int	id;

	if (argc != 3)
		return (1);
	id = fork();
	if (id == -1)
		return (1);
	if (id == 0)
		child_process(argv);
	waitpid(id, NULL, 0);
	return (0);
}
