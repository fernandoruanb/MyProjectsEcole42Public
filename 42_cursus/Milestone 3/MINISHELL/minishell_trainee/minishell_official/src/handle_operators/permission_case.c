/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:51:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/27 11:41:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	permission_case(int *pipefd, t_ast **root, t_data *data, int flag)
{
	if (ft_strcmp((*root)->cmd[0], "sudo") == 0)
	{
		if (flag == 1)
			close_descriptors(pipefd, 1, data);
		else if (flag == 0)
			close_descriptors(pipefd, 0, data);
		return (0);
	}
	return (1);
}
