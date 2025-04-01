/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-microshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:22:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/01 10:01:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

typedef struct s_shell
{
	char	**envp;
	int	isPipe;
	char	*cmd;
	char	**cmds;
	int	pipefd[2];
}	t_shell;

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return ((unsigned char)s1[index] && (unsigned char)s2[index]);
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
		ft_putendl_fd("microshell: PIPE Error", 2);
		exit(1);
	}
}

static void	execute_command(t_shell *shell)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (shell->isPipe)
		{
			dup2(shell->pipefd[1], STDOUT_FILENO);
			close(shell->pipefd[1]);
			close(shell->pipefd[0]);
		}
		if (execve(shell->cmd, shell->cmds, shell->envp) == -1)
		{
			ft_putendl_fd("microshell: execve error", 2);
			exit(1);
		}
	}
	else
	{
		if (shell->isPipe)
		{
			dup2(shell->pipefd[0], STDIN_FILENO);
			close(shell->pipefd[0]);
			close(shell->pipefd[1]);
		}
		waitpid(pid, NULL, 0);
	}
}

static int	cd_command(t_shell *shell)
{
	if (ft_strcmp(shell->cmd, "cd") != 0)
		return (1);
	else if (!shell->cmds[1] || shell->cmds[2])
		return (1);
	if (chdir(shell->cmds[1]) == -1)
		ft_putendl_fd("microshell: cd: error", 2);
	return (0);
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
		*argv = &(*argv)[index];
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
		return (1);
	++argv;
	return (microshell(argv, &shell));
}
