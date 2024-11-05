/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:19:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/05 09:56:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <fcntl.h>*/
#include "get_next_line.h"

/*int	main(int argc, char **argv)
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
	if (get_next_line(file_descriptor) != NULL)
		return (1);
	close(file_descriptor);
	return (0);
}*/

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	size_t		start;
	char		*line;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		start = 0;
		while (start < (size_t)bytes_read)
		{
			line = (print_line(buffer, &start, bytes_read);
			if (!line)
				return (NULL);
			write(1, line, len);
			free_memory(&line);
		}
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	return (NULL);
}
