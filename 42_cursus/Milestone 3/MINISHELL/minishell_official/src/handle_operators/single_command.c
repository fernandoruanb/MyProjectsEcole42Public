/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:36:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/27 12:02:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	choose_correct_message(t_ast **root)
{
	if ((*root)->cmd[0][0] == '/')
		ft_putstr_fd(" No such file or directory\n", 2);
	else
		ft_putstr_fd(" command not found\n", 2);
}

static int	check_is_directory_op(char *cmd, t_utils *data)
{
	if (stat(cmd, &data->stat_check) == -1)
		return (0);
	if (S_ISDIR(data->stat_check.st_mode))
		return (1);
	return (0);
}

void	single_command(t_ast **root, t_data *data)
{
	int		pid;

	if (!*root || (*root)->id != CMD)
		return ;
	if (check_is_directory_op((*root)->cmd[0], &data->utils))
	{
		if ((*root)->cmd[0][0] == '.')
		{
			ft_putstr_fd(" Is a directory\n", 2);
			data->utils.exec_status = 126;
			return ;
		}
		choose_correct_message(root);
		data->utils.exec_status = 127;
		return ;
	}
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		check_errno((*root)->cmd, &data->utils, data);
	waitpid(pid, &data->utils.exec_status, 0);
	translate(data);
}
