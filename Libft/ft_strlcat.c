/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:56:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/16 18:56:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/
#include <stddef.h>

size_t	ft_strlen(const char *s);

void	*ft_memcpy(void *dest, const void *src, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

/*int	main(int argc, char **argv)
{
	int	result;

	if (argc < 4)
		return (1);
	result = ft_strlcat(argv[1], argv[2], atoi(argv[3]));
	printf("(MY FUNCTION) %i.\n", result);
	return (0);
}*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	disponible;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (len_dst >= size)
		return (size + len_src);
	disponible = size - len_dst;
	if (len_src < disponible)
	{
		ft_memcpy(dst + len_dst, src, len_src);
		dst[len_dst + len_src] = '\0';
	}
	else
	{
		ft_memcpy(dst + len_dst, src, disponible - 1);
		dst[len_dst + disponible - 1] = '\0';
	}
	return (len_dst + len_src);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
