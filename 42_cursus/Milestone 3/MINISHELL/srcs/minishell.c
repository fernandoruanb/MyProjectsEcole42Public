/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:13:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/28 19:14:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handle_signal(int signal)
{
	if (signal == SIGINT)
		ft_printf("\n\033[1;92m<<Master of Minishell(mini)>>$\033[0m ");
	if (signal == SIGQUIT)
		return ;
}

static void	init_data(t_data *data, char **envp)
{
	data->envp = envp;
	data->pipes = 0;
	data->redirect_in = 0;
	data->redirect_out = 0;
	data->redirect_out_append = 0;
	data->redirect_in_heredoc = 0;
	data->redirect_in_triple = 0;
	data->redirect_out_triple = 0;
	data->line = NULL;
}

static void	display_prompt(t_data *data, char **envp)
{
	while (1)
	{
		data->line = readline("\033[1;92m<<Master of Minishell(mini)>>$\033[0m ");
		if (data->line == NULL || ft_strncmp(data->line, "exit", 4) == 0)
		{
			if (data->line == NULL)
				ft_printf("exit\n");
			if (data->line != NULL)
				free(data->line);
			rl_clear_history();
			break ;
		}
		add_history(data->line);
		if (!builtins(data))
			execute(data, envp);
		if (data->line != NULL)
			free(data->line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1)
		return (1);
	(void)argv;
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
	init_data(&data, envp);
	display_prompt(&data, envp);
	return (0);
}
