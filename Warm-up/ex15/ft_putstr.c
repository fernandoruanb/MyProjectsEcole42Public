/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 07:59:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/18 07:59:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str);

/*int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	ft_putstr(argv[1]);
	ft_putchar('\n');
	return (0);
}*/

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
