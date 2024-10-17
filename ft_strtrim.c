/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:15:05 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/17 12:15:08 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char	*ft_strtrim(char const *s1, char const *s2);

int	main(int argc, char **argv)
{
	char	*result;

	if (argc < 3)
		return (1);
	result = ft_strtrim(argv[1], argv[2]);
	printf("(MY FUNCTION) %s.\n", result);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s1[index] != '\0')
	{
		if (s1[index] == s2[index])
			count++;
		index++;
	}
}
