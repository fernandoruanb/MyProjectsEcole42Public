/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:28:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/30 14:43:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

/*void	*ft_memchr(const void *s, int c, size_t n);

int	main(int argc, char **argv)
{
	char	*result;
	char	*result2;

	if (argc < 4)
		return (1);
	result = ft_memchr(argv[1], argv[2][0], argv[3][0]);
	result2 = memchr(argv[1], argv[2][0], argv[3][0]);
	printf("(MY FUNCTION) %s.\n", result);
	printf("(ORIGINAL) %s.\n", result2);
	return (0);
}*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*ptr;
	size_t			length;

	index = 0;
	ptr = (unsigned char *)s;
	length = ft_strlen(s);
	while (index < n)
	{
		if (ptr[index] == (unsigned char)c)
			return ((char *)&ptr[index]);
		index++;
	}
	return (NULL);
}
