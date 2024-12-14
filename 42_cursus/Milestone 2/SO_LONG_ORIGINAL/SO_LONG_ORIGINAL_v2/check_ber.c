/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:14:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/14 14:28:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	if (!s1 || !s2)
		return (-2);
	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

static char	*ft_strrchr(const char *s, int c)
{
	size_t	length;

	length = ft_strlen(s);
	while (length >= 0)
	{
		if (s[length] == (unsigned char)c)
			return ((char *)&s[length]);
		length--;
	}
	return (NULL);
}

int	check_ber(const char *filename)
{
	char	*extension;
	char	*final_filename;

	extension = ".ber";
	final_filename = ft_strrchr(filename, '.');
	return (ft_strcmp(extension, final_filename));
}
