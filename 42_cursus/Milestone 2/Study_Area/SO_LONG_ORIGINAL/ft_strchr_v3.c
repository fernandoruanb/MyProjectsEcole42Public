/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_v3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:36:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/06 09:39:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr_v3(const char *s, int c)
{
	size_t	index;
	size_t	length;

	if (!s)
		return (NULL);
	index = 0;
	length = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[length]);
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (NULL);
}
