/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:39:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/02 09:40:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"
#include <stdio.h>

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while ((unsigned char)s1[index] != '\0' && (unsigned char)s2[index] != '\0')
	{
		if ((unsigned char)s1[index] != (unsigned char)s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

static void	ft_putstr_fd(const char *message, int fd)
{
	int	index;

	index = 0;
	while (message[index] != '\0')
	{
		write(fd, &message[index], 1);
		index++;
	}
}

static void	ft_putendl_fd(const char *message, int fd)
{
	int	index;

	index = 0;
	while (message[index] != '\0')
	{
		write(fd, &message[index], 1);
		index++;
	}
	write(fd, "\n", 1);
}

static void	init_pipe(t_shell *shell)
{
	if (shell->isPipe != 1)
		return ;
	if (pipe(shell->pipefd) == -1)
	{
		ft_putendl_fd("microshell: error fatal", 2);
		exit(1);
	}
}

static int	cd_command(t_shell *shell)
{
	if (ft_strcmp(shell->cmd, "cd") != 0)
		return (1);
	else if (!shell->cmds[1] || shell->cmds[2])
	{
		ft_putendl_fd("error: cd bad arguments", 2);
		return (0);
	}
	if (chdir(shell->cmds[1]) == -1)
	{
		ft_putstr_fd("error: cannot change directory to ", 2);
		ft_putendl_fd(shell->cmds[1], 2);
	}
	return (0);
}

static void	execute_command(t_shell *shell)
{
	int	pid;

	if (ft_strcmp(shell->cmd, "|") == 0 || ft_strcmp(shell->cmd, ";") == 0)
	{
		if (shell->isPipe)
		{
			close(shell->pipefd[1]);
			close(shell->pipefd[0]);
			return ;
		}
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		if (shell->isPipe)
		{
			if (dup2(shell->pipefd[1], STDOUT_FILENO) == -1)
			{
				ft_putendl_fd("microshell: error fatal", 2);
				exit(1);
			}
			close(shell->pipefd[1]);
			close(shell->pipefd[0]);
		}
		if (execve(shell->cmd, shell->cmds, shell->envp) == -1)
		{
			ft_putstr_fd("microshell: cannot execute ", 2);
			ft_putendl_fd(shell->cmd, 2);
			exit(1);
		}
	}
	else
	{
		if (shell->isPipe)
		{
			if (dup2(shell->pipefd[0], STDIN_FILENO) == -1)
			{
				ft_putendl_fd("microshell: error fatal", 2);
				exit(1);
			}
			close(shell->pipefd[1]);
			close(shell->pipefd[0]);
		}
		waitpid(pid, NULL, 0);
	}
}

static void	find_command(char ***argv, t_shell *shell)
{
	int	index;

	index = 0;
	while ((*argv)[index] && ft_strcmp((*argv)[index], "|") != 0
		&& ft_strcmp((*argv)[index], ";") != 0)
		index++;
	if ((*argv)[index] == NULL)
	{
		*argv = &((*argv)[index]);
		return ;
	}
	if (ft_strcmp((*argv)[index], "|") == 0)
		shell->isPipe = 1;
	(*argv)[index] = NULL;
	*argv = &(*argv)[index + 1];
}

static int	microshell(char **argv, t_shell *shell)
{
	while (*argv)
	{
		shell->isPipe = 0;
		shell->cmd = *argv;
		shell->cmds = argv;
		find_command(&argv, shell);
		init_pipe(shell);
		if (cd_command(shell))
			execute_command(shell);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	shell.envp = envp;
	if (argc == 1)
		return (0);
	++argv;
	return (microshell(argv, &shell));
}
