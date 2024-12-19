/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:45:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/19 16:29:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_memory(char ***str_list, int allocated)
{
	int	index;

	if (!str_list || !*str_list)
		return (0);
	index = 0;
	while (index < allocated)
	{
		free((*str_list)[index]);
		index++;
	}
	free(*str_list);
	return (0);
}

static int	fill_arr(int size, const char *s, char ***str_list)
{
	int		counter;
	int		index;
	int		pass;
	char	*new_str;

	counter = 0;
	index = 0;
	while (s[index] != '\0' && counter < size)
	{
		pass = 0;
		while ((s[index]) && s[index] == ' ')
			index++;
		while ((s[index + pass]) && s[index + pass] != ' ')
			pass++;
		new_str = ft_substr(&s[index], 0, pass);
		if (!new_str)
			return (free_memory(str_list, counter));
		(*str_list)[counter] = new_str;
		counter++;
		index += pass;
	}
	(*str_list)[size] = NULL;
	return (1);
}

static int	count_words(const char *s)
{
	int		index;
	int		count;
	size_t	length;

	length = ft_strlen(s);
	if (length == 0)
		return (0);
	index = 0;
	count = 0;
	while (s[index] != '\0')
	{
		if ((s[index]) && s[index] != ' ')
		{
			while ((s[index] && s[index] != ' '))
				index++;
			count++;
		}
		if (s[index] != '\0')
			index++;
	}
	return (count);
}

char	**ft_split(const char *s)
{
	int		size;
	char	**str_list;

	if (!s)
		return (ft_calloc(1, sizeof(char *)));
	size = count_words(s);
	if (size == 0)
		return (ft_calloc(1, sizeof(char *)));
	str_list = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!str_list)
		return (NULL);
	if (!fill_arr(size, s, &str_list))
		return (NULL);
	return (str_list);
}

int	main(int argc, char **argv)
{
	int		index;
	char	**result;

	if (argc != 2)
	{
		printf("How to use: [STRING].\n");
		return (1);
	}
	index = 0;
	result = ft_split(argv[1]);
	if (!result)
		return (1);
	while (result[index] != NULL)
	{
		printf("Array[%d]: %s\n", index, result[index]);
		free(result[index]);
		index++;
	}
	free(result);
	return (0);
}
