/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:13:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/28 13:35:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handle_signal(int signal)
{
	if (signal == SIGINT)
		ft_printf("\n\033[1;92m<<Master of Minishell(mini)>>$\033[0m ");
}

static void	init_data(t_data *data)
{
	data->pipes = 0;
	data->redirect_in = 0;
	data->redirect_out = 0;
	data->redirect_out_append = 0;
	data->redirect_in_heredoc = 0;
	data->redirect_in_triple = 0;
	data->redirect_out_triple = 0;
}

static void	display_prompt(char **envp)
{
	t_data	data;
	char	*line;

	line = NULL;
	while (1)
	{
		signal(SIGINT, handle_signal);
		line = readline("\033[1;92m<<Master of Minishell(mini)>>$\033[0m ");
		if (line == NULL || ft_strncmp(line, "exit", 4) == 0)
		{
			if (line == NULL)
				ft_printf("exit\n");
			if (line != NULL)
				free(line);
			rl_clear_history();
			break ;
		}
		add_history(line);
		execute(line, &data, envp);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1)
		return (1);
	(void)argv;
	init_data(&data);
	display_prompt(envp);
	return (0);
}
