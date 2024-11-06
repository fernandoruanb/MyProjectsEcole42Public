/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/06 11:42:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buffer(char **buffer)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	index;

	if (!dst || !src)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

char	*extract_line(char **buffer)
{
	char	*line;
	char	*new_buffer;
	size_t	len;

	if (!*buffer || **buffer == '\0')
		return (NULL);
	if (ft_strchr(*buffer, '\n'))
	{
		len = ft_strchr(*buffer, '\n') - *buffer + 1;
		line = ft_substr(*buffer, 0, len);
		new_buffer = ft_strdup(*buffer + len);
		free(buffer);
		buffer = new_buffer;
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		buffer = NULL;
	}
	return (line);

}

char	*read_to_buffer(int fd, char *buffer)
{
	char	*temp;
	char	read_buf[BUFFER_SIZE + 1];
	ssize_t bytes_read;

	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
	
	read_buf[bytes_read] = '\0';
	temp = ft_strjoin(buffer, read_buf);
	free(buffer);
	buffer = temp;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
