/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:31:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/19 15:31:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	len;
	int	index;

	index = 0;
	len = 0;
	while (str[index] != '\0')
	{
		len++;
		index++;
	}
	return (len);
}
//int	main(void)
//{
//
//	int	tamanho;
//
//	tamanho = ft_strlen("Hello, World!");
//	printf("O tamanho da minha string 'Hello, World! é: %d.", tamanho);
//	return (0);
//}
// Caro avaliador, não esqueça de colocar a biblioteca <stdio.h>
