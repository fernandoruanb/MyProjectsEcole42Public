/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:49:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/23 12:56:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n);

int	main(int argc, char **argv)
{
	int	count;

	(void)argv;
	count = argc - 1;
	ft_putnbr(count);
	write(1, "\n", 1);
	return (0);
}

void	ft_putnbr(int n)
{
	long	num;
	char	digit;

	num = n;
	if (n < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (n >= 10)
		ft_putnbr((int)num / 10);
	digit = (num % 10) + '0';
	write(1, &digit, 1);
}
