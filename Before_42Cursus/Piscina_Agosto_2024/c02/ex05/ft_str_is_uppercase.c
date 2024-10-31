/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:08:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/20 15:08:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < 'A' || str[index] > 'Z')
			return (0);
		index++;
	}
	return (1);
}
/*int	main(void)
{
	char	*str;
	int	result;

	str = "HELLO";
	result = ft_str_is_uppercase(str);
	printf("A string bonita a ser passada é: %s\n", str);
	printf("O resultado é: %i\n", result);
	return (0);
}
Caro avaliador, não esquecer da <stdio.h>
*/
