/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:25:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/20 15:25:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < ' ' || str[index] > '~')
			return (0);
		index++;
	}
	return (1);
}
int	main(void)
{
	char	*str;
	int	result;

	str = "\n\t\b\r";
	printf("A string bonita a ser testada é: %s\n", str);
	result = ft_str_is_printable(str);
	printf("O resultado é: %i\n", result);
	return (0);
}
//Caro avaliador, não esquecer de colocar a <stdio.h>

