/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:54:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 17:05:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s);

int	main(int argc, char **argv)
{
	size_t	length;
	size_t	index;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	length = ft_strlen(argv[1]);
	index = 0;
	while ((argv[1][length - 1]) && (argv[1][length - 1] == ' '
		|| argv[1][length - 1] == '\t'))
		length--;
	while ((argv[1][length - 1]) && (argv[1][length - 1] != ' '
		&& argv[1][length - 1] != '\t'))
	{
		length--;
		index++;
	}
	while (index > 0)
	{
		write(1, &argv[1][length], 1);
		length++;
		index--;
	}
	write(1, "\n", 1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
