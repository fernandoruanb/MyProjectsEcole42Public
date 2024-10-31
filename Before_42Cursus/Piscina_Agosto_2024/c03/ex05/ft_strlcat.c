/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:28:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/02 15:28:26 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>*/

int	ft_strlcat(char *dest, char *src, unsigned int size);

/*int	main(int argc, char **argv)
{
	(void) argc;
	char	*s1;
	char	*s2;
	int	limiter = 10;
	int	result;

	if (argc < 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	result = ft_strlcat(s1, s2, limiter);
	printf("O resultado da minha função ficou: %i\n", result);
	printf("A string dest está: %s\n", s1);
	return (0);
}
*/
int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	index;

	len_dest = 0;
	len_src = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	while (src[len_src] != '\0')
		len_src++;
	if (len_dest >= size)
		return (size + len_src);
	index = 0;
	while ((len_dest + index) < (size - 1) && src[index] != '\0')
	{
		dest[len_dest + index] = src[index];
		index++;
	}
	dest[len_dest + index] = '\0';
	return (len_dest + len_src);
}
