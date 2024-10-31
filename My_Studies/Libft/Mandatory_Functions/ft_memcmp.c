/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:48:22 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/30 15:03:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

/*int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	main(int argc, char **argv)
{
	int	result;
	int	result2;

	if (argc < 4)
		return (1);
	result = ft_memcmp(argv[1], argv[2], atoi(argv[3]));
	result2 = memcmp(argv[1], argv[2], atoi(argv[3]));
	printf("(MY FUNCTION) %d.\n", result);
	printf("(ORIGINAL) %d.\n", result2);
	return (0);
}*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	index = 0;
	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (index < n - 1)
	{
		if (ptr1[index] != ptr2[index])
			return ((unsigned char)ptr1[index] - (unsigned char)ptr2[index]);
		index++;
	}
	return ((unsigned char)ptr1[index] - (unsigned char)ptr2[index]);
}
