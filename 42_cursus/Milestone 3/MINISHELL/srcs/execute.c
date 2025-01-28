/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:26:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/28 13:56:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	find_pipes(char *line, t_data *data)
{
	int	index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '|')
			data->pipes++;
		index++;
	}
}

/*static void	exec_complex_cmd(char *l, char **s_l, t_data *data, char **envp)
{
	static int	index;
	static int	last_pipe;
	char	**args;

	if (data->pipes > 0)
		data->pipes--;
	while (ft_strcmp(s_l[index], "|") != 0 && s_l[index])
		index++;
	last_pipe = index;
	args = (char **)malloc(sizeof(char *) * (index));
	if (!args)
		return ;
	index = 0;
	while (index < last_pipe)
	{
		args[index] = s_l[index];
		index++;
	}
	args[index] = NULL;
	execute_command(args, envp);
	central_control(l, s_l, data, envp);

}*/

static void	central_control(char *line, char **s_l, t_data *data, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		if (data->pipes == 0)
		{
			free_splits(NULL, s_l, NULL, NULL);
			execute_command(line, envp);
			exit(EXIT_SUCCESS);
		}
	}
	waitpid(pid, &data->status, 0);
}

void	execute(char *line, t_data *data, char **envp)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (!split_line)
		return ;
	find_pipes(line, data);
	central_control(line, split_line, data, envp);
}
