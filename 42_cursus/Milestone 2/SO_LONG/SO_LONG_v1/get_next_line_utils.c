/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:36:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/07 19:17:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_v2(const char *s1)
{
	size_t	index;
	size_t	length;
	char	*buffer;

	if (!s1)
		return (NULL);
	length = ft_strlen_v2(s1);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		buffer[index] = s1[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

char	*ft_strjoin_v2(const char *s1, const char *s2)
{
	size_t	index;
	size_t	len_s1;
	size_t	len_s2;
	char	*buffer;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen_v2(s1);
	len_s2 = ft_strlen_v2(s2);
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

void	*ft_calloc_v2(size_t nmemb, size_t size)
{
	size_t			index;
	unsigned char	*ptr;
	void			*buffer;
	size_t			length;

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

char	*ft_substr_v2(const char *s, unsigned int start, size_t len)
{
	size_t	index;
	size_t	length;
	char	*buffer;

	if (!s)
		return (ft_calloc_v2(1, sizeof(char)));
	length = ft_strlen_v2(s);
	if (start >= length)
		return (ft_calloc_v2(1, sizeof(char)));
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
