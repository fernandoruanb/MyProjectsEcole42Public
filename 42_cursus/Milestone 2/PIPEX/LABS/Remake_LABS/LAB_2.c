/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LAB_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:28:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/23 13:59:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

static int	close_descriptors(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	return (1);
}

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

static void	parent_process(char *message, int *pipefd)
{
	size_t	length;

	close(pipefd[0]);
	length = ft_strlen(message);
	write(pipefd[1], message, length);
	printf("The parent process sent a message: %s\n", message);
}

static void	child_process(char *message, int *pipefd)
{
	ssize_t	bytes_read;
	size_t	length;
	char	buffer[4096];

	close(pipefd[1]);
	if (!message)
		return ;
	length = ft_strlen(message);
	bytes_read = read(pipefd[0], buffer, sizeof(buffer));
	if (bytes_read == -1)
		return ;
	buffer[bytes_read] = '\0';
	printf("The child process received: %s\n", buffer);
}

int	main(int argc, char **argv)
{
	int	id;
	int	pipefd[2];

	if (argc != 2)
		return (1);
	if (pipe(pipefd) == -1)
		return (-1);
	id = fork();
	if (id == -1)
		return (close_descriptors(pipefd));
	if (id == 0)
		child_process(argv[1], pipefd);
	else
		parent_process(argv[1], pipefd);
	close_descriptors(pipefd);
	return (0);
}
