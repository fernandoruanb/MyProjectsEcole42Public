/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:23:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/19 09:23:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

size_t	word_len(const char *s, char c);

size_t	num_words(const char *s, char c);

char	*next_word(const char *s, char c);

char	**ft_split(char const *s, char c);

int	main(int argc, char **argv)
{
	char	**buffer;
	int	index;
	int	count;
	int	words;

	if (argc < 4)
		return (1);
	index = 0;
	count = 0;
	words = atoi(argv[3]);
	buffer = ft_split(argv[1], argv[2][0]);
	while (buffer[count] != NULL)
	{
		while (buffer[count][index] != '\0')
		{
			write(1, &buffer[count][index], 1);
			count++;
		}
		index++;
	}
	free(buffer);
	return (0);
}

size_t	num_words(const char *s, char c)
{
	size_t	total;
	size_t	index;

	index = 0;
	total = 0;
	while (s[index] != '\0' && s[index] == (unsigned char)c)
		index++;
	while (s[index] != '\0')
	{
		while (s[index] != '\0' && s[index] != (unsigned char)c)
			index++;
		total++;
		while (s[index] != '\0' && s[index] == (unsigned char)c)
			index++;
	}
	return (total);
}

size_t	word_len(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0' && s[length] != (unsigned char)c)
		length++;
	return (length);
}

char	*next_word(const char *s, char c)
{
	int	index;

	index = 0;
	while (s[index] != '\0' && s[index] == (unsigned char)c)
		index++;
	return ((char *)&s[index]);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	index;
	size_t	words;

	index = 0;
	if (s[0] != '\0')
	{
		words = num_words(s, (unsigned char)c);
		buffer = (char **)malloc(sizeof(char *) * words + 1);
		if (!buffer)
			return (NULL);
		while (index < words)
		{
			s = next_word(s, c);
			buffer[index] = ft_substr(s, 0, word_len(s, c));
			if (!buffer[index])
				return (NULL);
			index++;
		}
		buffer[words] = NULL;
	}
	else
		return (NULL);
	return (buffer);
}
