/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:20:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/20 18:20:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (index == 0 && str[index] >= 'a' && str[index] <= 'z')
			str[index] = str[index] - ('a' - 'A');
		else if ((str[index - 1] < '0'
				|| (str[index - 1] > '9' && str[index - 1] < 'A')
				|| (str[index - 1] > 'Z' && str[index - 1] < 'a')
				|| str[index - 1] > 'z')
			&& (str[index] >= 'a' && str[index] <= 'z'))
		{
			if (str[index] >= 'a' && str[index] <= 'z')
				(str[index] = str[index] - ('a' - 'A'));
			else if (str[index] >= 'A' && str[index] <= 'Z')
				(str[index] = str[index] + ('a' - 'A'));
		}
	index++;
	}
	return (str);
}
/*int	main(void)
{
	char text[] = "antonio da Silva lapolina de souza francisco melo";
	char *str;

	printf("A string bonita que será usada é: %s\n", text);
	str = ft_strcapitalize(text);
	printf("A nova string bonita é: %s\n", str);
	return (0);
}
//Caro avaliador, não esquecer de colocar a <stdio.h>
*/
