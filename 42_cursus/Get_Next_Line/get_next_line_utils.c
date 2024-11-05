/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:08:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/05 09:44:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*dynamic_str(const char *buffer, size_t len)
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

int	print_line(const char *buffer, size_t *start, ssize_t bytes_read)
{
	size_t	len;
	char	*dynamic_str_here;

	len = 0;
	while ((*start + len) < (size_t)bytes_read && buffer[*start + len] != '\n'
		&& buffer[*start + len] != '\0')
		len++;
	dynamic_str_here = dynamic_str(&buffer[*start], len);
	if (!dynamic_str_here)
		return (1);
	write(1, dynamic_str_here, len);
	free_memory(&dynamic_str_here);
	if (buffer[*start + len] == '\n')
	{
		write(1, "\n", 1);
		(*start) += len + 1;
	}
	else
		(*start) += len;
	return (0);
}
