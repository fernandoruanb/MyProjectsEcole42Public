/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:52:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/09 16:10:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t		index;
	size_t		length;
	char		*buffer;

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

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*buffer;
	size_t	index;

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	void			*buffer;
	size_t			length;
	size_t			index;

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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	length;
	size_t	index;
	char	*buffer;

	if (!s)
		return (ft_calloc(1, sizeof(char)));
	length = ft_strlen(s);
	if (start >= length)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > length)
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

char	*free_buffer(char **buffer, char **read_buf)
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
