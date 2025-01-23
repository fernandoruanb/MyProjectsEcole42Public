/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LAB_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:32:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/23 16:59:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

static int	close_descriptors(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	return (1);
}

static void	second_command(char **argv, int *pipefd)
{
	char	*args[3];

	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(pipefd[0]);
	args[0] = argv[3];
	args[1] = argv[4];
	args[2] = NULL;
	if (execve(args[0], args, NULL) == -1)
		exit(EXIT_FAILURE);
}

static void	first_command(char **argv, int *pipefd)
{
	char	*args[3];

	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(pipefd[1]);
	args[0] = argv[1];
	args[1] = argv[2];
	args[2] = NULL;
	if (execve(args[0], args, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int	id;
	int	id2;
	int	pipefd[2];

	if (argc != 5)
		return (1);
	if (pipe(pipefd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (close_descriptors(pipefd));
	if (id == 0)
		first_command(argv, pipefd);
	id2 = fork();
	if (id2 == -1)
		return (close_descriptors(pipefd));
	if (id2 == 0)
		second_command(argv, pipefd);
	close_descriptors(pipefd);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
