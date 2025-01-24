/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LAB_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:00:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/24 10:02:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../libft/libft.h"

int     close_descriptors(int *pipefd);

int     free_splits(char **split1, char **split2, char **split3);

static char	*find_path(char *cmd, char **paths)
{
	char	*true_temp;
	char	*true_path;
	int	index;

	index = 0;
	while (paths[index])
	{
		true_temp = ft_strjoin(paths[index], "/");
		if (!true_temp)
			return (NULL);
		true_path = ft_strjoin(true_temp, cmd);
		if (!true_path)
			return (NULL);
		if (access(true_path, F_OK | R_OK) == 0)
			return (true_path);
		index++;
	}
	return (NULL);
}

static int	execute_command(char *cmd, char **envp)
{
	char	*paths_temp;
	char	**paths;
	char	*path;
	int	index;
	char	**commands;

	index = 0;
	while (!ft_strnstr(envp[index], "PATH", 4))
		index++;
	paths_temp = ft_strdup(envp[index] + 5);
	if (!paths_temp)
		return (1);
	paths = ft_split(paths_temp, ':');
	if (!paths)
		return (free_splits(&paths_temp, NULL, NULL));
	commands = ft_split(cmd, ' ');
	if (!commands)
		return (free_splits(&paths_temp, paths, NULL));
	path = find_path(commands[0], paths);
	if (!path)
		return (free_splits(&paths_temp, paths, commands));
	if (execve(path, commands, NULL) == -1)
		exit(EXIT_FAILURE);
	return (1);
}

static void	second_command(char **argv, char **envp, int *pipefd)
{
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return ;
	close(pipefd[0]);
	execute_command(argv[2], envp);
}

static void	first_command(char **argv, char **envp, int *pipefd)
{
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		return ;
	close(pipefd[1]);
	execute_command(argv[1], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	id;
	int	id2;
	int	pipefd[2];

	if (argc != 3)
		return (1);
	if (pipe(pipefd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (close_descriptors(pipefd));
	if (id == 0)
		first_command(argv, envp, pipefd);
	id2 = fork();
	if (id2 == -1)
		return (close_descriptors(pipefd));
	if (id2 == 0)
		second_command(argv, envp, pipefd);
	close_descriptors(pipefd);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
