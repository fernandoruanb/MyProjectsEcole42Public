/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_nothing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 08:39:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/03 15:56:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static size_t	ft_strlen_check(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

int	is_nothing(char **result)
{
	char	*str_check;
	int		index;

	index = 1;
	str_check = "";
	while (result[index])
	{
		if (ft_strcmp(result[index], str_check) == 0
			|| result[index][0] == '\0'
			|| ft_strlen_check(result[index]) == 0)
			return (1);
		index++;
	}
	return (0);
}
