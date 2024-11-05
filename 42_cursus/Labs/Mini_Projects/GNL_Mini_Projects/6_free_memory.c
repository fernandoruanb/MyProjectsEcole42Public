/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_free_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:32:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/05 09:02:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

static int	read_and_write(int fd);

static char	*dynamic_str(const char *buffer, size_t len);

static int	print_line(const char *buffer, size_t *start, ssize_t bytes_read);

static void	free_memory(char **ptr);

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
		write(1, "Error opening file.\n", 20);
		return (1);
	}
	if (read_and_write(file_descriptor) == 1)
		return (1);
	close(file_descriptor);
	return (0);
}

static char	*dynamic_str(const char *buffer, size_t len)
{
	size_t	index;
	char	*str;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (index < len)
	{
		str[index] = buffer[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

static int	read_and_write(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	size_t		start;

	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		start = 0;
		buffer[bytes_read] = '\0';
		while (start < (size_t)bytes_read)
		{
			if (print_line(buffer, &start, bytes_read) == 1)
				return (1);
		}
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	if (bytes_read == 0)
	{
		write(1, "\nI read everything.\n", 20);
		return (1);
	}
	return (0);
}

static int	print_line(const char *buffer, size_t *start, ssize_t bytes_read)
{
	size_t	len;
	char	*dynamic_str_here;

	len = 0;
	while ((*start + len) < (size_t)bytes_read && buffer[*start + len] != '\n'
			&& buffer[*start + len] != '\0')
		len++;
	dynamic_str_here = dynamic_str(&buffer[*start], len);
	if (!dynamic_str_here)
		return (1);
	write(1, dynamic_str_here, len);
	free_memory(&dynamic_str_here);
	if (buffer[*start + len] == '\n')
	{
		write(1, "\n", 1);
		(*start) += len + 1;
	}
	else
		(*start) += len;
	return (0);
}

static void	free_memory(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
