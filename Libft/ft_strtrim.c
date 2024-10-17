/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:28:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/17 10:28:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char	*erase_caracters(char *buffer, const char *s2);

size_t	ft_strlen(const char *s);

char	*ft_strtrim(const char *s1, const char *s2);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 4)
		return (1);
	result = ft_strtrim(argv[1], argv[2]);
	printf("(MY FUNCTION) %s.\n", result);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *s2)
{
	int		index;
	char	*buffer;
	int		length;

	index = 0;
	length = ft_strlen(s1);
	buffer = (char *)malloc(length + 1);
	while (s1[index] != '\0')
	{
		buffer[index] = s1[index];
		index++;
	}
	buffer[index] = '\0';
	buffer = erase_caracters(buffer, s2);
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

char	*erase_caracters(char *buffer, const char *s2)
{
	int	index;
	int	length;

	index = 0;
	length = ft_strlen(buffer);
	while (buffer[index] != '\0' && s2[index] != '\0')
	{
		if (buffer[index] == s2[index])
			buffer[index] = 0;
		index++;
	}
	index = 0;
	while (length >= 0 && s2[index] != '\0')
	{
		if (buffer[length] == s2[index])
			buffer[length] = 0;
		length--;
		index++;
	}
	buffer[length] = '\0';
	return (buffer);
}
