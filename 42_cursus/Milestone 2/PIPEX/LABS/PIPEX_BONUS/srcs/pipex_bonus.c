/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:14:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/26 09:30:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	index;
	int	pipefds[1024][2];
	int	pids[1024];

	if (argc < 5)
		return (ft_putendl_fd_1("Too few args.", 2));
	if (!create_pipes(argc, pipefds))
		return (1);
	index = 0;
	while (index < argc - 1)
	{
		pid = create_fork();
		if (pid == -1)
			exit(clean_all_pipes_also_fd(argc, pipefds, 0));
		if (pid == 0)
			execute_each_command(index, pipefds, argv, envp);
		pids[index] = pid;
		index++;
	}
	clean_all_pipes_also_fd(argc, pipefds, 0);
	index = 0;
	while (index < argc - 1)
		waitpid(pids[index++], NULL, 0);
	return (0);
}
