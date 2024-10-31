/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:18:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/20 11:18:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] < 'a' || str[index] > 'z')
			&& (str[index] < 'A' || str[index] > 'Z'))
			return (0);
	index++;
	}
	return (1);
}
/*int	main(void)
{
	char	*str = "Hello, World!";
	int	come_back;
	printf("A string a ser testada é %s\n", str);
	printf("Vou capturar o retorno da função\n");
	come_back = ft_str_is_alpha(str);
	printf("O retorno da função é: %i", come_back);
	return (0);
}
Caro avaliador, não esquecer de colocar a biblioteca <stdio.h>
*/
