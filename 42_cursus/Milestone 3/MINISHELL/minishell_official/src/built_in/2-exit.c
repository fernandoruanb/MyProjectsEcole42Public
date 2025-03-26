/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:47:20 by jopereir          #+#    #+#             */
/*   Updated: 2025/03/26 19:50:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_sig(char c)
{
	return (c == '+' || c == '-');
}

static int	is_all_num(char *str)
{
	int	i;
	size_t	length;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && !is_sig(str[i]))
		{
			ft_putstr_fd(" numeric argument required\n", 2);
			return (0);
		}
		length = ft_strlen(str);
		if (length > 19)
		{
			ft_putstr_fd(" numeric argument required\n", 2);
			return (0);
		}
	}
	return (1);
}

void	ft_exit(t_data *data, char **exit_status)
{
	int	len;

	rl_clear_history();
	data->prompt->exit_status = 0;
	if (exit_status && exit_status[1])
	{
		len = splitlen(exit_status);
		if (len > 2)
		{
			ft_putstr_fd(" too many arguments\n", 2);
			data->prompt->exit_status = 1;
		}
		else if (is_all_num(exit_status[1]))
			data->prompt->exit_status = ft_atoi_but_better(exit_status[1]);
		else
			data->prompt->exit_status = 2;
	}
	clear_split(data->utils.paths);
	if (data->flags.should_clean)
		call_clean(data, data->flags.shoud_restore);
	destroy(data, NULL, data->prompt->exit_status);
}
