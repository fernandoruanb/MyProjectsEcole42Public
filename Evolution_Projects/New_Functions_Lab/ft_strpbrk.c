/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:52:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/18 19:09:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static size_t	ft_strlen(const char *s);

static char		*ft_strchr(const char *s, int c);

char			*ft_strpbrk(const char *s1, const char *s2);

int	main(int argc, char **argv)
{
	char	*result;
	char	*result2;

	if (argc < 3)
		return (1);
	result = ft_strpbrk(argv[1], argv[2]);
	result2 = strpbrk(argv[1], argv[2]);
	printf("(MY FUNCTION) %s\n", result);
	printf("(ORIGINAL) %s\n", result2);
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0')
	{
		if (ft_strchr(s2, s1[index]))
			return ((char *)&s1[index]);
		index++;
	}
	return (NULL);
}

static char	*ft_strchr(const char *s, int c)
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

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
