/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:47:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/20 11:47:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	fill_arrays(int size, const char *s, const char c, char ***str_list);

static int	count_words(const char *s, const char c);

/*char	**ft_split(char const *s, char c);

int	main(int argc, char **argv)
{
	char	**result;
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (argc < 3)
		return (1);
	result = ft_split(argv[1], argv[2][0]);
	index = 0;
	while (result[index] != 0)
	{
		while (result[index][count] != '\0')
		{
			write(1, &result[index][count], 1);
			count++;
		}
		index++;
	}
	return (0);
}*/

char	**ft_split(char const *s, char c)
{
	int	size;
	char	**str_list;

	size = count_words(s, c);
	if (size == 0)
		return (ft_calloc(1, sizeof(char *)));
	str_list = (char **)ft_calloc((size + 1), sizeof(char *));
	if (!str_list)
		return (0);
	fill_arrays(size, s, c, &str_list);
	return (str_list);
}

static int	count_words(const char *s, const char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[index] != '\0')
	{
		if (s[index] != (unsigned char)c)
		{
			while (s[index] != (unsigned char)c
				&& s[index] != '\0')
				index++;
			count++;
			if (s[index] != '\0')
				index++;
		}
	}
	return (count);
}

static void	fill_arrays(int size, const char *s, const char c, char ***str_list)
{
	int	counter;
	int	index;
	int	pass;

	index = 0;
	counter = 0;
	while (s[index] != '\0' && counter < size)
	{
		pass = 0;
		while (s[index] == (unsigned char)c)
			index++;
		while (s[index + pass] && s[index + pass] != c)
			pass++;
		while (s[index] != '\0')
			index++;
		(*str_list)[counter] = ft_substr(&s[index], 0, pass);
		counter++;
	}
}
