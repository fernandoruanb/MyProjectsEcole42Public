/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:43:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/20 14:43:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
			return (0);
		index++;
	}
	return (1);
}
/*int	main(void)
{
	char	*str = "123";
	int	result;

	printf("A string a ser testada é: %s\n", str);
	result = ft_str_is_numeric(str);
	printf("É tudo número? %i\n", result);
	return (0);

}
Caro avaliador, não esquecer de colocar a <stdio.h>
*/
