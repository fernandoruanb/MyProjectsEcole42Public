/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:07:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/18 19:07:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char c);

char	*memory_each_word(const char *str, char c);

int	main(int argc, char **argv)
{
	return (0);
}

char	*memory_each_word(const char *str, char c)
{
	
}

int	count_words(const char *str, char c)
{
	int	index;
	int	how_many_words;
	int	word;

	index = 0;
	how_many_words = 0;
	is_word = 0;
	while (s[index] != '\0')
	{
		if (s[index] != (unsigned char)c
			&& !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (s[index] == (unsigned char)c)
			is_word = 0;
		index++;
	}
	return (how_many_words);
}
