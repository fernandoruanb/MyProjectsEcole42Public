/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_father_signal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:15:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/07 22:15:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	kill_all_processes(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->utils.num_of_processes)
	{
		kill(data->utils.pids[index], SIGINT);
		index++;
	}
}

static void	handle_father_sig(int signal)
{
	t_data	*minishell;

	minishell = get_minishell();
	if (signal == SIGINT || signal == SIGQUIT)
	{
		minishell->utils.mortal_dead = 1;
		kill_all_processes(minishell);
		minishell->utils.num_of_processes = 0;
		minishell->utils.index = 0;
		if (signal == SIGINT)
			minishell->utils.exec_status = 130;
		else
			minishell->utils.exec_status = 131;
	}
}

void	handle_father_signal(void)
{
	signal(SIGINT, handle_father_sig);
	signal(SIGQUIT, handle_father_sig);
}
