/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:06:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/30 13:14:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	main(int argc, char **argv)
{
	int	result;
	int	result2;

	if (argc < 4)
		return (1);
	result = ft_strncmp(argv[1], argv[2], atoi(argv[3]));
	result2 = strncmp(argv[1], argv[2], atoi(argv[3]));
	printf("(MY FUNCTION) %d.\n", result);
	printf("(ORIGINAL) %d.\n", result2);
	return (0);
}*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0' && index < n)
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	if (index < n)
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (0);
}
