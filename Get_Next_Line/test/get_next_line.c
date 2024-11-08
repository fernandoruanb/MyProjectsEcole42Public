/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:42:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/08 12:07:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **buffer)
{
	char	*new_buffer;
	char	*line;
	size_t	len;

	if (ft_strchr(*buffer, '\n'))
	{
		len = ft_strchr(*buffer, '\n') - *buffer + 1;
		line = ft_substr(*buffer, 0, len);
		new_buffer = ft_strdup(*buffer + len);
		free_buffer(buffer, NULL);
		buffer = new_buffer;
	}
	else
	{
		line
}

char	*read_to_buffer(int fd, char *buffer)
{
	char	*temp;
	char	*read_buf;
	ssize_t	bytes_read;

	bytes_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	read_buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_buffer(&buffer, &read_buf));
		read_buf[bytes_read] = '\0';
		temp = ft_strjoin(buffer, read_buf);
		free_buffer(&buffer, NULL);
		buffer = temp;
	}
	free_buffer(&read_buf, NULL);
	if ((buffer[0] = '\0' || !buffer) && bytes_read == 0)
		return (free_buffer(&buffer, NULL));
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
		return (free_buffer(&buffer, NULL));
	return (line);
}
