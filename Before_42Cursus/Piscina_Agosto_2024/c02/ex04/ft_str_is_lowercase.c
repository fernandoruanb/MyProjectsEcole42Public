/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:54:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/20 14:55:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < 'a' || str[index] > 'z')
			return (0);
		index++;
	}
	return (1);
}
/*int	main(void)
{
	char	*str;
	int	result;

	str = "";
	printf("A string bonita a ser testada é: %s\n", str);
	result = ft_str_is_lowercase(str);
	printf("A string é tudo letra minúscula? %i\n", result);
	return (0);
}
Caro avaliador, não esquecer de colocar o <stdio.h>
*/
