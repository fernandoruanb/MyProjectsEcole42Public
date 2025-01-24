/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:52:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/23 18:53:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*is_valid_cmd(char *cmd, char **paths)
{
	int		index;
	char	*true_temp;
	char	*true_cmd;

	index = 0;
	while (paths[index])
	{
		true_temp = ft_strjoin(paths[index], "/");
		true_cmd = ft_strjoin(true_temp, cmd);
		if (access(true_cmd, F_OK | X_OK) == 0)
		{
			free(true_temp);
			return (true_cmd);
		}
		else
		{
			free(true_cmd);
			free(true_temp);
		}
		index++;
	}
	return (NULL);
}
