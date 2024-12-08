/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:10:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/08 14:15:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strtrim(const char *s, char *set)
{
	char	*buffer;
	int		end;
	int		index;

	index = 0;
	end = ft_strlen(s) - 1;
	while (ft_strchr(s, s[end]))
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
