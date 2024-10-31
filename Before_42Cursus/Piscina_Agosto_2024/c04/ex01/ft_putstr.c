/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:55:28 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/25 11:55:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <stdio.h>*/

void	ft_putstr(char *str);

/*int	main(int argc, char **argv)
{
	(void) argc;
	char	*str;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	printf("O resultado da minha função é: \n");
	ft_putstr(str);
	printf("\n");
	printf("O resultado na oficial é: \n");
	puts(str);
	return (0);
}
*/
void	ft_putstr(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	write(1, str, length);
}
