/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:25:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/08 17:05:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strtrim(const char *s, const char *set)
{
	int		index;
	int		end;
	char	*buffer;

	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	while (end > 0 && ft_strchr_v3(set, s[end]))
		end--;
	buffer = (char *)malloc(end + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (index < end)
	{
		buffer[index] = s[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

int	check_newline(char **map)
{
	char	*buffer;
	int		length;
	int		length_2;
	int		index;

	length = ft_strlen(map[0]) - 2;
	index = 0;
	while (map[index] != NULL)
	{
		buffer = ft_strtrim(map[index], "\n");
		if (!buffer)
			return (ft_putstr_fd_0("Error buffer size\n", 2));
		length_2 = ft_strlen(buffer);
		free(buffer);
		if (length != length_2 && map[index + 1] != NULL)
			return (0);
		if (length != length_2 && map[index + 1] == NULL)
			return (0);
		index++;
	}
	return (1);
}
