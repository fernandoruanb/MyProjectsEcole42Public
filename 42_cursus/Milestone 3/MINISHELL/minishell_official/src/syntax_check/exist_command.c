/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:53:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/10 13:22:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exist_command(t_token *root, t_utils *data)
{
	int	index;

	if (!data->paths)
		return (1);
	index = 0;
	while (data->paths[index] != NULL)
	{
		get_full_path(root, index, data);
		if (!data->path)
			return (0);
		if (access(data->path, F_OK) == 0)
		{
			data->status = 1;
			return (1);
		}
		index++;
	}
	return (0);
}
