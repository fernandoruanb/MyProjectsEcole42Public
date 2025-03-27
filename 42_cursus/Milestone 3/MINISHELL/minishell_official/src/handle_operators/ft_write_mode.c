/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:57:28 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/27 17:46:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_write_mode(int *pipefd, t_ast **root, t_data *data)
{
	char	*path;
	t_ast	*ast;

	ast = *root;
	handle_command_signal();
	permission_case(pipefd, root, data, 0);
	path = NULL;
	if (data->utils.can_write)
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
	close_descriptors(pipefd, 1, data);
	path = get_path(data, ast->cmd);
	if (!handle_builtin(ast->cmd, data))
		if (execve(path, ast->cmd, data->utils.envp) < 0)
			data->utils.exec_status = errno;
	free(path);
	close_all_fds();
	clean_process(data);
	exit(data->utils.exec_status);
}
