/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:01:52 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/14 14:01:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			length;
	void			*buffer;
	unsigned char	*ptr;
	size_t			index;

	index = 0;
	length = nmemb * size;
	buffer = malloc(length);
	if (!buffer)
		return (NULL);
	ptr = (unsigned char *)buffer;
	while (index < length)
	{
		ptr[length] = 0;
		length++;
	}
	return (buffer);
}
