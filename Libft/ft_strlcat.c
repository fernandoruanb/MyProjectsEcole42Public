/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:49:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/15 13:49:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdlib.h>
#include <stdio.h>*/
#include <stddef.h>

size_t	ft_strlen(const char *s);

/*size_t	ft_strlcat(char *dest, const char *src, size_t size);

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 2)
		return (1);
	result = ft_strlcat(argv[1], argv[2], atoi(argv[3]));
	printf("(MY FUNCTION) %i.\n", result);
	return (0);
}*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	index;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (len_dst >= size)
		return (size + len_src);
	index = 0;
	while ((len_dst + index) < (size - 1) && src[index] != '\0')
	{
		dest[len_dst + index] = src[index];
		index++;
	}
	if (len_dst < size)
		dest[len_dst + index] = '\0';
	return (len_dst + len_src);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
