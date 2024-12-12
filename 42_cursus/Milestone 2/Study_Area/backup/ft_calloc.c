/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:36:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/04 15:39:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	void			*buffer;
	size_t			index;
	size_t			length;

	if (nmemb != 0 && size > ((size_t) - 1) / nmemb)
		return (NULL);
	length = nmemb * size;
	buffer = malloc(length);
	if (!buffer)
		return (NULL);
	ptr = (unsigned char *)buffer;
	index = 0;
	while (index < length)
	{
		ptr[index] = 0;
		index++;
	}
	return (buffer);
}
