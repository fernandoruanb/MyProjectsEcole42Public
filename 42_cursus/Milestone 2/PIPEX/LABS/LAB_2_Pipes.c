/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LAB_2_Pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:11:15 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/23 13:25:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

static void	parent_process(char **argv, int *pipefd)
{
	int	length;

	close(pipefd[0]);
	length = ft_strlen(argv[1]);
	write(pipefd[1], argv[1], length);
	close(pipefd[1]);
	printf("The parent sent the message %s\n", argv[1]);
}

static void	child_process(char **argv, int *pipefd)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	close(pipefd[1]);
	bytes_read = read(pipefd[0], buffer, sizeof(buffer));
	if (bytes_read == -1)
		return ;
	close(pipefd[0]);
	buffer[bytes_read] = '\0';  
	printf("The child received the message: %s\n", buffer);
}

int	main(int argc, char **argv)
{
	int	id;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (1);
	if (id == 0)
		child_process(argv, pipefd);
	else
		parent_process(argv, pipefd);
	return (0);
}
