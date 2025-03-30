/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 10:23:52 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/30 11:09:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct s_shell
{
	int	isPipe;
	char	*cmd;
	char	**cmds;
	int	pipefd[2];
	char	**envp;
}	t_shell;

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] && s2[index])
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
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
		ft_putendl_fd("Error initializing the pipe", 2);
		exit(1);
	}
}

static void	execute_command(char **arguments, t_shell *shell)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(shell->pipefd[1], STDOUT_FILENO);
		close(shell->pipefd[1]);
		close(shell->pipefd[0]);
		if (execve(shell->cmd, shell->cmds, shell->envp) == -1)
		{
			ft_putendl_fd("microshell: error executing\n");
			exit(1);
		}
	}
	else
	{
		if (shell->isPipe)
		{
			dup2(shell->pipefd[0], STDIN_FILENO);
			close(shell->pipefd[1]);
			close(shell->pipefd[0]);
		}
		waitpid(pid, NULL, NULL);
	}
}

static void	find_command(char ***arguments, t_shell *shell)
{
	int	index;

	index = 0;
	while ((*arguments)[index] && ft_strcmp((*arguments)[index], "|") != 0
		&& ft_strcmp((*arguments)[index], ";") != 0)
		index++;
	if ((*arguments)[index] == NULL)
	{
		*arguments = &(*arguments)[index];
		return ;
	}
	if ((*arguments)[index] == '|')
		shell->isPipe = 1;
	(*arguments)[index] == NULL;
	*arguments = (*arguments)[index + 1];
}

static int	cd_command(char **arguments, t_shell *shell)
{
	if (ft_strcmp(*arguments, "cd") != 0)
		return (0);
	else if (!arguments[1] || arguments[2])
		return (1);
	if (chdir(arguments[1] == -1))
		ft_putendl("Cd error\n");
	return (1);
}

static int	microshell(char **arguments, t_shell *shell)
{
	while (*arguments)
	{
		shell->isPipe = 0;
		shell->cmd = *arguments;
		shell->cmds = arguments;
		find_command(&arguments, shell);
		init_pipe(shell);
		if (!cd_command(arguments, shell))
			execute_command(arguments, shell);
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
