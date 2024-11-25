/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:13:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 15:18:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(char *src);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 2)
		return (1);
	result = ft_strdup(argv[1]);
	printf("%s\n", result);
	free(result);
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*buffer;
	size_t	index;
	size_t	length;

	if (!src)
		return (NULL);
	length = ft_strlen(src);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		buffer[index] = src[index];
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
