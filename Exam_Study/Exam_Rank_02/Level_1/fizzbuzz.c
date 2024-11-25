/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:01:19 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 10:14:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fizzbuzz(int number);

void	ft_putnbr(int n);

int	main(void)
{
	int	number;

	number = 1;
	while (number <= 100)
	{
		fizzbuzz(number);
		number++;
	}
	return (0);
}

void	ft_putnbr(int n)
{
	char	digit;
	long	num;

	num = n;
	if (num < 0)
	{
		write(1, "\n", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr((int)num / 10);
	digit = (num % 10) + '0';
	write(1, &digit, 1);
}

void	fizzbuzz(int number)
{
	if (number % 3 == 0 && number % 5 == 0)
		write(1, "fizzbuzz\n", 9);
	else if (number % 3 == 0)
		write(1, "fizz\n", 5);
	else if (number % 5 == 0)
		write(1, "buzz\n", 5);
	else
	{
		ft_putnbr(number);
		write(1, "\n", 1);
	}
}
