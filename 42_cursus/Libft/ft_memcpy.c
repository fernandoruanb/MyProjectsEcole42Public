/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:46:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/15 14:46:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>*/
#include <stddef.h>

/*void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main(int argc, char **argv)
{
	char	*result;
	char	*result2;

	if (argc < 4)
		return (1);
	result = ft_memcpy(argv[1], argv[2], atoi(argv[3]));
	result2 = memcpy(argv[1], argv[2], atoi(argv[3]));
	printf("(MY FUNCTION) %s.\n", result);
	printf("(ORIGINAL) %s.\n", result2);
	return (0);
}*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;
	size_t				index;

	ptr1 = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	index = 0;
	while (index < n)
	{
		ptr1[index] = ptr2[index];
		index++;
	}
	return (dest);
}
