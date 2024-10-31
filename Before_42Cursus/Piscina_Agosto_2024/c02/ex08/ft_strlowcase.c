/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:06:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/20 16:06:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] = str[index] - ('A' - 'a');
		index++;
	}
	return (str);
}
/*int	main(void)
{
	char text[] = "OI, TUDO BEM?";
	char *str;

	printf("A string bonita usada para teste é: %s\n", text);
	str = ft_strlowcase(text);
	printf("A nova string bonita é: %s\n", str);
	return (0);
}
Caro avaliador, por favor ponha a biblioteca <stdio.h>
*/
