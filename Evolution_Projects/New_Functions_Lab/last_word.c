/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:32:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/20 15:09:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(const char *s);

void			last_word(char *s);

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}

void	last_word(char *s)
{
	int		count;
	int		index;
	size_t	length;

	length = ft_strlen(s);
	count = 0;
	while (length > 0 && (s[length - 1] == ' ' || s[length - 1] == '\t'))
		length--;
	while (length > 0 && (s[length - 1] != ' ' && s[length - 1] != '\t'))
	{
		count++;
		length--;
	}
	index = 0;
	while (index < count)
	{
		write(1, &s[length], 1);
		index++;
		length++;
	}
}

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
