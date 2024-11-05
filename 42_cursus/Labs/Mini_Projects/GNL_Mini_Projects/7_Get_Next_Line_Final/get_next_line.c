/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:26:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/05 15:19:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

ssize_t	read_into_buffer(int fd, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read >= 0)
		buffer[bytes_read] = '\0';
	return (bytes_read);
}

char	*append_line(char *line, char *buffer)
{
	ssize_t	newline_pos;

	newline_pos = find_newline(buffer);
	if (newline_pos == -1)
		newline_pos = ft_strlen(buffer);
	line = ft_strjoin(line, buffer, newline_pos);
	process_buffer(buffer, newline_pos);
	return (line);
}

void	process_buffer(char *buffer, ssize_t newline_pos)
{
	ssize_t	index;

	index = 0;
	while (buffer[newline_pos] != '\0')
		buffer[index++] = buffer[newline_pos++];
	buffer[index] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (buffer[0] == '\0')
			bytes_read = read_into_buffer(fd, buffer);
		if (bytes_read == -1)
		{
			free_memory(&line);
			return (NULL);
		}
		line = append_line(line, buffer);
		if (!line)
			return (NULL);
		if (find_newline(buffer) != -1)
			break ;
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int	file_descriptor;
	char	*line;
	
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
	while ((line = get_next_line(file_descriptor)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(file_descriptor);
	return (0);
}
