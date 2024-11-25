/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:16:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 19:07:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

int	main(int argc, char **argv)
{
	char	buffer[256];
	int	index;
	int	count;

	if (argc < 3 || argc > 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	count = 0;
	while (argv[1][index] != '\0')
	{
		if (!ft_strchr(buffer, argv[1][index]))
		{
			write(1, &argv[1][index], 1);
			buffer[count] = argv[1][index];
			count++;
		}
		index++;
	}
	index = 0;
	while (argv[2][index] != '\0')
	{
		if (!ft_strchr(buffer, argv[2][index]))
		{
			write(1, &argv[2][index], 1);
			buffer[count] = argv[2][index];
			count++;
		}
		index++;
	}
	write(1, "\n", 1);
	return (0);
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

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
