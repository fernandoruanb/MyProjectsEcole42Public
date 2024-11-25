/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:03:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 15:11:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

size_t	ft_strcspn(const char *s, const char *reject);

int	main(int argc, char **argv)
{
	size_t	result;
	size_t	result2;

	result = ft_strcspn(argv[1], argv[2]);
	printf("%zu\n", result);
	result2 = strcspn(argv[1], argv[2]);
	printf("%zu\n", result2);
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	length;

	if (!s)
		return (0);
	length = 0;
	while (s[length] != '\0' && !ft_strchr(reject, s[length]))
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	length;
	size_t	index;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[length]);
	index = 0;
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
