/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:16:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/21 16:16:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	(void) argc;
	char	*s1 = argv[1];
	char	*s2 = argv[2];
	int	result;
	int	result2;

	if (argc < 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	printf("As duas strings bonitas para teste: %s %s\n", s1, s2);
	result = ft_strcmp(s1, s2);
	result2 = strcmp(s1, s2);
	printf("O resultado com a original é: %i\n", result2);
	printf("O resultado é: %i\n", result);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0'
		&& s2[index] != '\0')
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
