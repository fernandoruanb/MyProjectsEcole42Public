/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LAB_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:52:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/24 13:48:23 by fruan-ba         ###   ########.fr       */
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

static void	third_command(char *cmd, char **envp, int *pipefd, int *pipefd2)
{
	close_descriptors(pipefd);
	close(pipefd2[1]);
	if (dup2(pipefd2[0], STDIN_FILENO) == -1)
		return ;
	close(pipefd2[0]);
	execute_command(cmd, envp);
}

static void	second_command(char *cmd, char **envp, int *pipefd, int *pipefd2)
{
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return ;
	if (dup2(pipefd2[1], STDOUT_FILENO) == -1)
		return ;
	close(pipefd2[0]);
	close(pipefd[0]);
	execute_command(cmd, envp);
}

static void	first_command(char *cmd, char **envp, int *pipefd)
{
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		return ;
	close(pipefd[1]);
	execute_command(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	id;
	int	id2;
	int	id3;
	int	pipefd[2];
	int	pipefd2[2];

	if (argc != 4)
		return (1);
	if (pipe(pipefd) == -1)
		return (1);
	if (pipe(pipefd2) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (close_descriptors(pipefd));
	if (id == 0)
		first_command(argv[1], envp, pipefd);
	id2 = fork();
	if (id2 == -1)
		return (close_descriptors(pipefd));
	if (id2 == 0)
		second_command(argv[2], envp, pipefd, pipefd2);
	id3 = fork();
	if (id3 == -1)
		return (close_descriptors(pipefd));
	if (id3 == 0)
		third_command(argv[3], envp, pipefd, pipefd2);
	close_descriptors(pipefd);
	close_descriptors(pipefd2);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
	waitpid(id3, NULL, 0);
	return (0);
}
