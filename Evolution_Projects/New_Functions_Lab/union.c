/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:40:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/21 09:18:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

static size_t	ft_strlen(const char *s);

static char		*ft_strchr(const char *s, int c);

void			union_display(const char *s1, const char *s2);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 3 || argc > 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	union_display(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

void	union_display(const char *s1, const char *s2)
{
	char	buffer[256];
	int		index;
	int		count;
	int		s_index;

	index = 0;
	count = 0;
	s_index = 0;
	while (s1[index] != '\0')
	{
		write(1, &s1[index], 1);
		index++;
	}
	while (s2[s_index] != '\0')
	{
		if (!ft_strchr(s1, s2[s_index]) && !ft_strchr(buffer, s2[s_index]))
		{
			buffer[count] = s2[s_index];
			write(1, &s2[s_index], 1);
			count++;
		}
		s_index++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	size_t	length;

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

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
