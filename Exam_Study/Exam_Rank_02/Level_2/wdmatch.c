/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:08:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 19:39:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s);

int	main(int argc, char **argv)
{
	int	index;
	int	s_index;
	int	length;

	if (argc < 3 || argc > 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 0;
	s_index = 0;
	length = ft_strlen(argv[1]);
	while (argv[1][index] != '\0' && argv[2][s_index] != '\0')
	{
		if (argv[1][index] == argv[2][s_index])
		{
			index++;
			s_index = 0;
		}
		else
			s_index++;
	}
	if (argv[1][index] == '\0')
		write(1, argv[1], length);
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
