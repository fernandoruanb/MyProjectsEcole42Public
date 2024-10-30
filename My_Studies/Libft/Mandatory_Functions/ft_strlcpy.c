/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:37:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/30 09:42:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 4)
		return (1);
	result = ft_strlcpy(argv[1], argv[2], atoi(argv[3]));
	printf("(MY FUNCTION) %d.\n", result);
	return (0);
}*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	index;

	len_src = ft_strlen(src);
	index = 0;
	if (size <= 0)
		return (len_src);
	while (index < (size - 1) && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (len_src);
}
