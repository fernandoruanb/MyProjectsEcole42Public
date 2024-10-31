/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:53:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/25 16:53:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <stdio.h>
#include "../ex03/ft_atoi.c"*/

void	ft_putnbr(int nb);

/*int	main(int argc, char **argv)
{
	(void) argc;
	char	*number;
	int	nb;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	number = argv[1];
	nb = ft_atoi(number);
	ft_putnbr(nb);
	return (0);
}
*/
void	ft_putnbr(int nb)
{
	char	digit;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	digit = '0' + (nb % 10);
	write(1, &digit, 1);
}
