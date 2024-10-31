/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 07:58:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/24 07:58:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	src_len;

	index = 0;
	src_len = 0;
	if (size > 0)
	{
		while (index < (size - 1) && src[index] != '\0')
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	while (src[src_len] != '\0')
		src_len++;
	return (src_len);
}
/*int	main(void)
{
	char dest[100];
	char *src = "Oi, tudo bem?";
	unsigned int size = 14;
	unsigned int result;

	printf("A string bonita que será usada para teste é: %s\n", src);
	result = ft_strlcpy(dest, src, size);
	printf("O resultado é de caracteres da src é: %i\n", result);
	printf("A string dest ficou: %s\n", dest);
	return (0);
}
Caro avaliador, não se esquecer da <stdio.h>
*/
