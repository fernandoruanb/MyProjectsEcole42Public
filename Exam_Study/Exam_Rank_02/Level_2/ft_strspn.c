/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:04:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 16:15:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

size_t	ft_strspn(const char *s, const char *accept);

int	main(int argc, char **argv)
{
	size_t	result;
	size_t	result2;

	if (argc < 3)
		return (1);
	result = ft_strspn(argv[1], argv[2]);
	result2 = strspn(argv[1], argv[2]);
	printf("%zu\n", result);
	printf("%zu\n", result2);
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	int	length;

	length = 0;
	while (s[length] != '\0' && ft_strchr(accept, s[length]))
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	size_t	length;

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

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
