/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:00:59 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/22 19:34:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	parent_process(char **argv, char **envp, int *pipefd)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY, O_CREATE, O_TRUNC);
	if (fileout == -1)
		return ;
	if (dup2(pipefd[0], STDIN_FILENO) == 0)
	{
		close(fileout);
		return ;
	}
	if (dup2(fileout, STDOUT_FILENO) != 0)
	{
		close(fileout);
		return ;
	}
	close(pipefd[1]);
	execute_command(argv[3], envp);
}

static void	child_process(char **argv, char **envp, int *pipefd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		return ;
	if (dup2(pipefd[1], STDOUT_FILENO) == 0)
	{
		close(filein);
		return ;
	}
	if (dup2(filein, STDIN_FILENO) == 0)
	{
		close(filein);
		return ;
	}
	close(pipefd[0]);
	execute_command(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	id;

	if (argc == 5)
	{
		if (pipe(pipefd) == -1)
			return (ft_putendl_fd_1("Error setting the pipe connection.", 2));
		id = fork();
		if (id == -1)
		{
			close(pipefd[0]);
			close(pipefd[1]);
			return (ft_putendl_fd_1("Error creating the child process.", 2));
		}
		if (id == 0)
			child_process(argv, envp, pipefd);
		waitpid(id, NULL, 0);
		parent_process(argv, envp, pipefd);
	}
	else
		return (ft_putendl_fd_1("./pipex <infile> <cmd1> <cmd2> <outfile>", 2));
	return (0);
}
