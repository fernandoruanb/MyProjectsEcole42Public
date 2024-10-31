/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:33:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/20 08:33:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
/*int	main(void)
{
	char dest[50];
	char *src = "Hello, World!";

	printf("String bonita usada para teste: %s\n", src);
	ft_strcpy(dest, src);
	printf("A string copiada é: %s\n", dest);
	return (0);
}
Caro avaliador, não esquecer da <stdio.h>
Não se esquecer de passar nossa diva norminette
*/
