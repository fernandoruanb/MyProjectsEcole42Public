/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:11:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/30 09:15:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

/*void	ft_bzero(void *s, size_t n);

int	main(int argc, char **argv)
{
	char	*result;
	char	*result2;

	if (argc < 2)
		return (1);
	ft_bzero(argv[1], atoi(argv[2]));
	bzero(argv[1], atoi(argv[2]));
	printf("(MY FUNCTION) %s.\n", result);
	printf("(ORIGINAL) %s.\n", result2);
	return (0);
}*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			index;

	ptr = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		ptr[index] = 0;
		index++;
	}
}
