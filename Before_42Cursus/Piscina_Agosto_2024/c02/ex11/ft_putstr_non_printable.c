/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 09:32:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/24 09:32:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_hex(char c);

void	ft_putstr_non_printable(char *str);

/*int	main(void)
{
	char	*str;

	str = "H\tllo World!\n";
	printf("A string original era: %s\n", str);
	ft_putstr_non_printable(str);
	return (0);
}
Caro avaliador, não esquecer da <stdio.h>
*/

void	ft_putstr_non_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] < ' ' || str[index] > '~')
		{
			print_hex(str[index]);
		}
		else
			write(1, &str[index], 1);
		index++;
	}
	write(1, "\n", 1);
}

void	print_hex(char c)
{
	char	hex[2];

	if (c / 16 >= 10)
		hex[0] = 'a' + (c / 16) - 10;
	else
		hex[0] = '0' + (c / 16);
	if (c % 16 >= 10)
		hex[1] = 'a' + (c % 16) - 10;
	else
		hex[1] = '0' + (c % 16);
	write(1, "\\", 1);
	write(1, hex, 2);
}
