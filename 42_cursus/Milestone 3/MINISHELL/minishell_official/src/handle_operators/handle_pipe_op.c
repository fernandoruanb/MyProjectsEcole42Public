/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:45:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/03/25 16:37:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	read_mode(t_ast **root, int *pipefd, t_data *data)
{
	int	pid;

	if (check_is_directory_fd((*root)->cmd[0], &data->utils))
	{
		data->utils.exec_status = 512;
		close_descriptors(pipefd, 1, data);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		close_descriptors(pipefd, 1, data);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		ft_read_mode(root, pipefd, data);
	close_descriptors(pipefd, 1, data);
	data->utils.pids[data->utils.index++] = pid;
	data->utils.num_of_processes++;
}

void	write_mode(t_ast **root, int *pipefd, t_data *data)
{
	int	pid;

	data->utils.fd_backup = dup(pipefd[0]);
	if (data->utils.fd_backup == -1)
		close_descriptors(pipefd, 1, data);
	if (check_is_directory_fd((*root)->cmd[0], &data->utils))
	{
		close_descriptors(pipefd, 0, data);
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		close_descriptors(pipefd, 1, data);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		ft_write_mode(pipefd, root, data);
	data->utils.pid = pid;
	data->utils.pids[data->utils.index++] = pid;
	data->utils.num_of_processes++;
}

void	write_read_mode(t_ast **root, int *pipefd, t_data *data)
{
	int		pid;
	int		fd;

	if (the_divine_eye(pipefd, root, data))
		return ;
	fd = dup(pipefd[0]);
	if (fd == -1)
		close_descriptors(pipefd, 1, data);
	pid = fork();
	if (pid == -1)
	{
		close_descriptors(pipefd, 1, data);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(fd);
		ft_write_read_mode(pipefd, root, data);
	}
	if (data->utils.fd_backup)
		close(data->utils.fd_backup);
	data->utils.fd_backup = fd;
	data->utils.pids[data->utils.index++] = pid;
	data->utils.num_of_processes++;
}

void	wait_all_pids(t_data *data)
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

int	handle_pipe_op(t_ast **root, int flag, t_data *data)
{
	int		pipefd[2];

	data->utils.exec_status = 0;
	if (pipe(pipefd) == -1)
		return (1);
	if (flag == 1)
		write_mode(root, pipefd, data);
	else if (flag == 2)
		read_mode(root, pipefd, data);
	else if (flag == 3)
		write_read_mode(root, pipefd, data);
	if (flag == 3 || flag == 1)
		close_descriptors(pipefd, 0, data);
	if (flag == 2)
		close_descriptors(pipefd, 1, data);
	if (flag == 2)
		wait_all_pids(data);
	return (data->utils.exec_status);
}

/*int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		index;

	if (argc < 2)
		return (1);
	data.utils.num_of_processes = 0;
	data.utils.exec_status = 0;
	data.utils.index = 0;
	(void)argc;
	data.utils.envp = envp;
	index = 1;
	handle_pipe_op(argv[index], 1, &data.utils);
	index++;
	while (index < argc - 1)
	{
		handle_pipe_op(argv[index], 3, &data.utils);
		index++;
	}
	handle_pipe_op(argv[argc - 1], 2, &data.utils);
	translate(&data.utils);
	printf("EXEC STATUS: %d\n", data.utils.exec_status);
	return (0);
}*/
