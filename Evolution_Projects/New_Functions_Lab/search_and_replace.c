/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:46:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/17 16:59:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s);

void	search_and_replace(char *c, const char search, const char replace);

int	main(int argc, char **argv)
{
	int		index;
	size_t	length;

	if (argc < 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	length = ft_strlen(argv[1]);
	while (argv[1][index] != '\0')
	{
		search_and_replace(&argv[1][index], argv[2][0], argv[3][0]);
		index++;
	}
	write(1, argv[1], length);
	write(1, "\n", 1);
	return (0);
}

void	search_and_replace(char *c, const char search, const char replace)
{
	if (*c == search)
		*c = replace;
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}