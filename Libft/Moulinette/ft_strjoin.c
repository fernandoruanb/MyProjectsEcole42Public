/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:21:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/17 08:21:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);

/*char	*ft_strjoin(char const *s1, char const *s2);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 3)
		return (1);
	result = ft_strjoin(argv[1], argv[2]);
	printf("(MY FUNCTION) %s.\n", result);
	free(result);
	return (0);
}*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len_dst;
	int		len_src;
	char	*buffer;
	int		index;
	int		count;

	len_dst = ft_strlen(s1);
	len_src = ft_strlen(s2);
	buffer = (char *)malloc(len_dst + len_src + 1);
	if (!buffer)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		buffer[index] = s1[index];
		index++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		buffer[index + count] = s2[count];
		count++;
	}
	buffer[index + count] = '\0';
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
