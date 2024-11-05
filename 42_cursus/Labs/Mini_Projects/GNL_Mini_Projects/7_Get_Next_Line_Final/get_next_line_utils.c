/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:01:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/05 15:07:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*dynamic_str(char *buffer, size_t len)
{
	size_t	index;
	char	*str;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (index < len)
	{
		str[index] = buffer[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

void	free_memory(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char *s2, size_t len)
{
	size_t	index_s1;
	size_t	index_s2;
	char	*buffer;

	if (!s1 && !s2)
		return (NULL);
	buffer = (char *)malloc(ft_strlen(s1) + len + 1);
	if (!buffer)
		return (NULL);
	index_s1 = 0;
	while (s1 && s1[index_s1])
	{
		buffer[index_s1] = s2[index_s1];
		index_s1++;
	}
	while (s2 && s2[index_s2])
	{
		buffer[index_s2] = s2[index_s2];
		index_s2++;
	}
	buffer[index_s1 + index_s2] = '\0';
	free_memory(&s1);
	return (buffer);
}

ssize_t	find_newline(char *buffer)
{
	ssize_t	index;

	index = 0;
	while (buffer[index] != '\0')
	{
		if (buffer[index] == '\n')
			return (index + 1);
		index++;
	}
	return (-1);
}
