/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_Dynamic_Buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:19:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/04 12:55:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

static char	*dynamic_str(const char *buffer, ssize_t bytes_read);

static int	read_and_write(int fd);

int	main(int argc, char **argv)
{
	int	file_descriptor;

	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		write(1, "Error opening file!.\n", 20);
		return (1);
	}
	if (read_and_write(file_descriptor) == 1)
		return (1);
	close(file_descriptor);
	return (0);
}

static char	*dynamic_str(const char *buffer, ssize_t bytes_read)
{
	int		index;
	char	*str;

	str = (char *)malloc(bytes_read + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (index < bytes_read)
	{
		str[index] = buffer[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

int	read_and_write(int fd)
{
	char	buffer[1024];
	ssize_t	bytes_read;
	char	*dynamic_str_here;

	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	dynamic_str_here = NULL;
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		free(dynamic_str_here);
		dynamic_str_here = dynamic_str(buffer, bytes_read);
		if (!dynamic_str_here)
			return (1);
		write(1, dynamic_str_here, bytes_read);
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	free(dynamic_str_here);
	return (0);
}
