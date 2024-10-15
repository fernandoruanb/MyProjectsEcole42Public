/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:53:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/15 09:53:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c);

/*void	ft_is_negative(int n);

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	ft_is_negative(atoi(argv[1]));
	ft_putchar('\n');
	return (0);
}*/

void	ft_is_negative(int n)
{
	if (n >= 0)
		ft_putchar('P');
	else
		ft_putchar('N');
}

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
