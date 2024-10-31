/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:35:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/27 18:35:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>*/

int	ft_atoi(char *str);

/*int	main(int argc, char **argv)
{
	(void) argc;
	char	*number;
	int	result;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	number = argv[1];
	result = ft_atoi(number);
	printf("O resultado ficou: %i\n", result);
	//"---+--+1234ab567"
	return (0);
}
*/
int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] < ' '
		|| str[i] == '\t' || str[i] == '\r' || str[i] == '\v')
			i++;
	while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}
