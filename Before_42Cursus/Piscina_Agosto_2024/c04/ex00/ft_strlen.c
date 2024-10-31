/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:41:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/25 10:41:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <string.h>
#include <stdio.h>
#include <unistd.h>*/

int	ft_strlen(char *str);

/*int	main(int argc, char **argv)
{
	(void) argc;
	char	*str;
	int	result;
	int	result2;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	result = ft_strlen(str);
	printf("O retorno da minha função é: %i\n", result);
	result2 = strlen(str);
	printf("O retorno da original é: %i\n", result2);
	return (0);
}
*/
int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}
