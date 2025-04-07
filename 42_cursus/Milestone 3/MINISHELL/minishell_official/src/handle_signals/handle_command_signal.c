/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_command_signal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:49:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 17:37:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	wait_all_processes(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->utils.num_of_processes - 1)
	{
		waitpid(data->utils.pids[index], &data->utils.exec_status, 0);
		translate(data);
		index++;
	}
	waitpid(data->utils.pids[index], &data->utils.exec_status, 0);
	translate(data);
}

static void	handle_command(int signal)
{
	t_data	*minishell;

	minishell = get_minishell();
	call_clean(minishell, minishell->flags.shoud_restore);
	clean_program(&minishell->utils);
	if (minishell->utils.index > 0)
	{
		minishell->utils.index = 0;
		minishell->utils.num_of_processes = 0;
		wait_all_processes(minishell);
	}
	if (signal == SIGINT)
		exit(130);
	else if (signal == SIGQUIT)
		exit(131);
}

void	handle_command_signal(void)
{
	signal(SIGINT, handle_command);
	signal(SIGQUIT, handle_command);
}
