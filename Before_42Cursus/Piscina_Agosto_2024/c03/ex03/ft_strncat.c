/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:55:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/21 19:56:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>
#include <unistd.h>*/

char	*ft_strncat(char *dest, char *src, unsigned int nb);

/*int	main(int argc, char **argv)
{
	(void)	argc;
	char	*dest;
	char	*src;
	char	*result;
	//char	*result2;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	dest = argv[1];
	src = argv[2];
	result = ft_strncat(dest, src, 5);
	printf("O resultado da minha função ficou: %s\n", result);
	//result2 = strncat(dest, src, 5);
	//printf("O resultado da função original ficou: %s\n", result2);
	return (0);
}
*/
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len_dest;
	unsigned int	index;

	len_dest = 0;
	index = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	while (index < nb && src[index] != '\0')
	{
		dest[len_dest + index] = src[index];
		index++;
	}
	dest[len_dest + index] = '\0';
	return (dest);
}
