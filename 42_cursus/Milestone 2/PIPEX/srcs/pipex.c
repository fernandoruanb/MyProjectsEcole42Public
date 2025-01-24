/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:14:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/24 15:16:47 by fruan-ba         ###   ########.fr       */
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
	int	id;
	int	id2;
	int	pipefd[2];

	if (argc != 5)
		return (1);
	if (pipe(pipefd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (close_descriptors(pipefd, NULL));
	if (id == 0)
		child_process(argv, envp, pipefd);
	id2 = fork();
	if (id2 == -1)
		return (close_descriptors(pipefd, NULL));
	if (id2 == 0)
		parent_process(argv, envp, pipefd);
	close_descriptors(pipefd, NULL);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
	return (0);
}
