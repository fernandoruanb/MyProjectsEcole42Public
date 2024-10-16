/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:40:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/17 08:40:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char	*allocate_memory(size_t len_s, unsigned int start, size_t len);

size_t	ft_strlen(const char *s);

/*char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 4)
		return (1);
	result = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
	printf("(MY FUNCTION) %s.\n", result);
	return (0);
}*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*buffer;
	size_t	index;

	len_s = ft_strlen(s);
	index = 0;
	buffer = allocate_memory(len_s, start, len);
	while (index < len)
	{
		buffer[index] = s[start];
		index++;
		start++;
	}
	buffer[index] = '\0';
	return (buffer);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*allocate_memory(size_t len_s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	size;

	if (start > len_s)
	{
		buffer = (char *)malloc(1);
		buffer[0] = '\0';
		return (buffer);
	}
	size = len_s - start;
	if (len_s - start < len)
		buffer = (char *)malloc(size - 1);
	else
		buffer = (char *)malloc(len + 1);
	return (buffer);
}
