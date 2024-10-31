/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:31:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/21 19:31:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(int argc, char **argv)
{
	(void) argc;
	char	*dest = argv[1];
	char	*src = argv[2];
	//char	*result;
	char	*result2;

	printf("As strings bonitas a serem testadas são: %s %s\n", dest, src);
	//result = ft_strcat(dest, src);
	//printf("O resultado da minha função é: %s\n", result);
	result2 = strcat(dest, src);
	printf("O resultado da original é: %s\n", result2);
	return (0);
}


char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	len_dest;

	len_dest = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	index = 0;
	while (src[index] != '\0')
	{
		dest[len_dest + index] = src[index];
		index++;
	}
	dest[len_dest + index] = '\0';
	return (dest);
}
