/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:21:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/01 08:34:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../42_cursus/Libft/libft.h"

static char	*allocate_memory(int len);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 4)
		return (1);
	result = ft_substr(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	printf("O resultado ficou: %s.\n", result);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*buffer;
	size_t	index;

	if (!s)
		return (ft_calloc(1, sizeof(char)));
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > len_s)
		len = len_s - start;
	buffer = allocate_memory(len);
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

static char	*allocate_memory(int len)
{
	char	*buffer;

	buffer = (char *)malloc(len + 1);
	if (!buffer)
		return (NULL);
	return (buffer);
}
