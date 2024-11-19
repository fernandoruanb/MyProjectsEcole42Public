/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 07:59:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/19 08:25:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

static size_t	ft_strlen(const char *s);

static char		*ft_strchr(const char *s, int c);

size_t			ft_strspn(const char *s, const char *accept);

int	main(int argc, char **argv)
{
	size_t	result;
	size_t	result2;

	if (argc < 3)
		return (1);
	result = ft_strspn(argv[1], argv[2]);
	result2 = strspn(argv[1], argv[2]);
	printf("(MY FUNCTION): %zu\n", result);
	printf("(ORIGINAL): %zu\n", result2);
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	int	index;
	int	length;

	index = 0;
	length = 0;
	while (s[index] != '\0')
	{
		if (ft_strchr(accept, s[index]))
			length++;
		if (!ft_strchr(accept, s[index + 1]))
			break ;
		index++;
	}
	return (length);
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
