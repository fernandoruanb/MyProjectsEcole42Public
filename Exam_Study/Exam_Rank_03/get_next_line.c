/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:48:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/09 16:39:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s);

static char	*ft_strchr(const char *s, int c);

static char	*ft_strdup(const char *s);

static char	*ft_strjoin(const char *s1, const char *s2);

static char	*ft_substr(const char *s, unsigned int start, size_t len);

static void	*ft_calloc(size_t nmemb, size_t size);

static char	*free_buffer(char **buffer, char **read_buf)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (read_buf && *read_buf)
	{
		free(*read_buf);
		*read_buf = NULL;
	}
	return (NULL);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;
	unsigned char	*ptr;
	size_t	index;
	size_t	length;

	if (nmemb != 0 && size > ((size_t) - 1) / nmemb)
		return (NULL);
	length = nmemb * size;
	buffer = malloc(length);
	if (!buffer)
		return (NULL);
	ptr = (unsigned char *)buffer;
	index = 0;
	while (index < length)
	{
		ptr[index] = 0;
		index++;
	}
	return (buffer);
}

static char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	length;
	char	*buffer;

	if (!s)
		return (ft_calloc(1, sizeof(char)));
	length = ft_strlen(s);
	if (start >= length)
		return (ft_calloc(1, sizeof(char)));
	if ((start + len) > length)
		len = length - start;
	buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (index < len)
	{
		buffer[index] = s[start];
		index++;
		start++;
	}
	buffer[index] = '\0';
	return (buffer);
}

static char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buffer;
	size_t	len_s1;
	size_t	len_s2;
	int	index;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	buffer = (char *)malloc(len_s1 + len_s2 + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (*s1)
		buffer[index++] = *s1++;
	while (*s2)
		buffer[index++] = *s2++;
	buffer[len_s1 + len_s2] = '\0';
	return (buffer);
}

static char	*ft_strdup(const char *s)
{
	size_t	index;
	size_t	length;
	char	*buffer;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		buffer[index] = s[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

static char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	size_t	length;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
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

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	if (!s)
		return (0);
	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

static char	*extract_line(char **buffer)
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
		*buffer = new_buffer;
	}
	else
	{
		line = ft_strdup(*buffer);
		free_buffer(buffer, NULL);
	}
	return (line);
}

static char	*read_to_buffer(char *buffer, int fd)
{
	char	*temp;
	char	*read_buf;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	read_buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
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
	if ((buffer[0] == '\0' || !buffer) && bytes_read == 0)
		return (free_buffer(&buffer, NULL));
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char	*line;

	if (fd == -1 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_to_buffer(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(&buffer[fd]);
	if (!line)
		return (free_buffer(&buffer[fd], NULL));
	return (line);
}

int	main(int argc, char **argv)
{
	int	file_descriptor;
	char	*line;

	if (argc < 2)
		return (1);
	if (argc > 2)
		return (1);
	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
		return (1);
	line = get_next_line(file_descriptor);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(file_descriptor);
	}
	if (file_descriptor > 2)
		close(file_descriptor);
	return (0);
}
