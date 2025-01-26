/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:07:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/26 18:08:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
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

