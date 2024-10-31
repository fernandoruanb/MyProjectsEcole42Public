/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:45:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/20 15:45:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 'a' && str[index] <= 'z')
			str[index] = str[index] - ('a' - 'A');
		index++;
	}
	return (str);
}
/*int	main(void)
{
	char text[] = "Fernando";
	char *str;

	printf("A string bonita usada para teste é: %s\n", text);
	str = ft_strupcase(text);
	printf("A nova string é: %s\n", str);
	return (0);
}
Caro avaliador, não esquecer de por a <stdio.h>
*/
