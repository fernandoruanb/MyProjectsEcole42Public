/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:32:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/06 19:32:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	size_t	length;
	size_t	index;

	if (!s1)
		return (NULL);
	length = ft_strlen(s1);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	while (s1[index] != '\0')
	{
		buffer[index] = s1[index];
		index++;
	}
	return (buffer);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	while (s[length] != '\0')
		length++;
	return (length);
}

char	*extract_line(char **buffer)
{
	char	*new_buffer;
	char	*line;
	size_t	len;

	if (ft_strchr(*buffer, '\n'))
	{
		len = ft_strchr(*buffer, '\n') - *buffer + 1;
		line = ft_substr(*buffer, 0, len);
		new_buffer = *buffer + len;
		free_buffer(buffer);
		buffer = new_buffer;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(buffer);
	}
	return (line);
}

char	*read_to_buffer(int fd, char *buffer)
{
	char	*temp;
	char	*read_buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!(ft_strchr(buffer, '\n') && bytes_read != 0))
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE - 1);
		if (bytes_read == -1)
			free_buffer(&buffer);
	}
	read_buf[bytes_read] = '\0';
	temp = ft_strjoin(buffer, read_buf);
	free_buffer(&buffer);
	buffer = temp;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	if (!line)
		free_buffer(&buffer);
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
	while ((line = get_next_line(file_descriptor) != NULL))
	{
		printf("%s", line);
		free(line);
	}	
	return (0);
}
