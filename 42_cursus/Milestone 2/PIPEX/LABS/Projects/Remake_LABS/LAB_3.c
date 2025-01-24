/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LAB_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:29:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/23 15:33:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

static void	child_process(char **commands)
{
	if (execve(commands[1], commands + 1, NULL) == -1)
	{
		printf("Oh noooo! We can't do anything to help you.\n");
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
