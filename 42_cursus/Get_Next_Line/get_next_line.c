/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:19:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 14:17:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//static int	find_next_line(char *buffer);

char	*get_next_line(int fd);

int	main(int argc, char **argv):
{
	int	file_descriptor;
	char	*buffer;

	if (argc < 2)
		return (1);
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
		return (1);
	buffer = get_next_line(file_descriptor);
	printf("O resultado foi: %s.\n", buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t	bytes_read;
	static char	buffer[BUFFER_SIZE + 1];
	int	index;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	index = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1 || bytes_read == 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	while (buffer[index] != '\n' && buffer[index] != '\0' && index < BUFFER_SIZE)
	{
		line = buffer[index];
		index++;
	}
	return (buffer);
}

/*static int	find_next_line(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] != '\0')
	{
		if (buffer[index] == '\n')
			return (index);
		index++;
	}
	return (index);
}*/
