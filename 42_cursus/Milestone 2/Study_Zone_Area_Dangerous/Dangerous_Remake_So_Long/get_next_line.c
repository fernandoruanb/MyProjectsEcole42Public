/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:24:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/10 12:58:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_v2(const char *s, int c)
{
	size_t	index;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen_v2(s);
	if (c == '\0')
		return ((char *)&s[length]);
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (NULL);
}

size_t	ft_strlen_v2(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*extract_line(char **buffer)
{
	char	*line;
	char	*new_buffer;
	size_t	len;

	if (ft_strchr_v2(*buffer, '\n'))
	{
		len = ft_strchr_v2(*buffer, '\n') - *buffer + 1;
		line = ft_substr_v2(*buffer, 0, len);
		if (!line)
			return (free_buffer(&line, NULL));
		new_buffer = ft_strdup_v2(*buffer + len);
		free_buffer(buffer, NULL);
		*buffer = new_buffer;
	}
	else
	{
		line = ft_strdup_v2(*buffer);
		free_buffer(buffer, NULL);
	}
	return (line);
}

char	*read_to_buffer(char *buffer, int fd)
{
	char	*temp;
	char	*read_buf;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_calloc_v2(1, sizeof(char));
	read_buf = ft_calloc_v2(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (!ft_strchr_v2(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_buffer(&buffer, &read_buf));
		read_buf[bytes_read] = '\0';
		temp = ft_strjoin_v2(buffer, read_buf);
		free_buffer(&buffer, NULL);
		buffer = temp;
	}
	free_buffer(&read_buf, NULL);
	if ((buffer[0] == '\0' || !buffer) && bytes_read == 0)
		return (free_buffer(&buffer, NULL));
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_to_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	if (!line)
		return (free_buffer(&buffer, NULL));
	return (line);
}
