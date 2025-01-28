/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:13:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/28 09:58:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	handle_signal(int signal)
{
	if (signal == SIGINT)
		ft_printf("\n\033[1;32mminishell>\033[0m ");
}

int	main(void)
{
	char	*line;

	line = NULL;
	while (1)
	{
		signal(SIGINT, handle_signal);
		line = readline("\033[1;32mminishell>\033[0m ");
		if (line == NULL || ft_strcmp(line, "exit") == 0)
		{
			if (line == NULL)
				ft_printf("exit\n");
			if (line != NULL)
				free(line);
			break ;
		}
		else
			add_history(line);
			//parsing_line(line);
		free(line);
	}
	return (0);
}
