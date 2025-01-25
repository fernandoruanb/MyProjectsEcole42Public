/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:14:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/25 19:06:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../libft/libft.h"

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
	int	pid;
	int	index;
	int	pipefds[1024][2];
	int	pids[1024];

	if (argc < 5)
		return (ft_putendl_fd_1("Too few args.", 2));
	if (!create_pipes(argc, pipefds))
		return (1);
	index = 0;
	while (index < argc - 1)
	{
		pid = create_fork(argc);
		if (pid == -1)
			exit(clean_all_pipes(argc, pipefds));
		if (pid == 0)
			execute_each_command(index, pipefds, argv, envp);
		pids[index] = pid;
		index++;
	}
	clean_all_pipes(argc, pipefds);
	index = 0;
	while (index < argc - 1)
		waitpid(pids[index++], NULL, 0);
	return (0);
}
