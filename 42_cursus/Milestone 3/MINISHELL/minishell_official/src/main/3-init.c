/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:09:27 by jopereir          #+#    #+#             */
/*   Updated: 2025/03/24 15:41:24 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_data(t_data *data, char **envp)
{
	data->prompt = ft_calloc(1, sizeof(t_prompt));
	if (!data->prompt)
		return (1);
	data->prompt->input = NULL;
	data->prompt->path = NULL;
	data->prompt->exit_status = 0;
	data->token = NULL;
	data->local_vars = NULL;
	data->envp = NULL;
	data->original_envp = envp;
	data->is_pipe = 0;
	data->utils.paths = NULL;
	data->flags.should_clean = true;
	data->root = NULL;
	data->flags.shoud_restore = false;
	data->export_vars = NULL;
	export_init(envp, &data->export_vars);
	return (0);
}
