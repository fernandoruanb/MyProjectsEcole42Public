/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:24:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/30 09:29:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

/*void	*ft_memmove(void *dest, const void *src, size_t n);

int	main(int argc, char **argv)
{
	char	*result;
	char	*result2;

	if (argc < 4)
		return (1);
	result = ft_memmove(argv[1], argv[2], atoi(argv[3]));
	result2 = memmove(argv[1], argv[2], atoi(argv[3]));
	printf("(MY FUNCTION) %s.\n", result);
	printf("(ORIGINAL) %s.\n", result2);
	return (0);
}*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;
	size_t				index;

	if (!dest && !src)
		return (NULL);
	ptr1 = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	index = 0;
	if (ptr1 > ptr2 && ptr1 < (ptr2 + n))
	{
		while (n > 0)
		{
			ptr1[n - 1] = ptr2[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
