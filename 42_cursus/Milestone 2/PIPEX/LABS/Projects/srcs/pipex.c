/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:14:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/23 19:19:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	execute_command(char *cmd, char **envp)
{
	char	*path;
	char	**paths;
	int		index;
	char	**cmds;
	char	*command;

	index = 0;
	while (!ft_strnstr(envp[index], "PATH", 4))
		index++;
	cmds = ft_split(cmd, ' ');
	if (!cmds)
		return (1);
	path = ft_strdup(envp[index] + 5);
	if (!path)
		return (free_splits(cmds, NULL, NULL));
	paths = ft_split(path, ':');
	if (!paths)
		return (free_splits(cmds, &path, NULL));
	command = is_valid_cmd(cmds[0], paths);
	if (!command)
		return (free_splits(cmds, &path, paths));
	if (execve(command, cmds, NULL) == -1)
		exit(EXIT_FAILURE);
	return (1);
}

static void	parent_process(char **argv, char **envp, int *pipefd)
{
	int	file_output;

	close(pipefd[1]);
	file_output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_output == -1)
		return ;
	if (dup2(file_output, STDOUT_FILENO) == -1)
		return ;
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return ;
	close(pipefd[0]);
	close(file_output);
	execute_command(argv[3], envp);
}

static void	child_process(char **argv, char **envp, int *pipefd)
{
	int	file_input;

	close(pipefd[0]);
	file_input = open(argv[1], O_RDONLY);
	if (file_input == -1)
		return ;
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		return ;
	if (dup2(file_input, STDIN_FILENO) == -1)
		return ;
	close(pipefd[1]);
	close(file_input);
	execute_command(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
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
		child_process(argv, envp, pipefd);
	id2 = fork();
	if (id2 == -1)
		return (close_descriptors(pipefd));
	if (id2 == 0)
		parent_process(argv, envp, pipefd);
	close_descriptors(pipefd);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
