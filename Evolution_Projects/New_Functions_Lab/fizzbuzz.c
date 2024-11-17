/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 08:41:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/17 09:01:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr(int number);

static void	fizzbuzz(int number);

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

static void	fizzbuzz(int number)
{
	if (number % 3 == 0 && number % 5 == 0)
	{
		write(1, "fizzbuzz\n", 9);
		return ;
	}
	else if (number % 3 == 0)
	{
		write(1, "fizz\n", 5);
		return ;
	}
	else if (number % 5 == 0)
	{
		write(1, "buzz\n", 5);
		return ;
	}
	else
		ft_putnbr(number);
	write(1, "\n", 1);
}

static void	ft_putnbr(int number)
{
	char	digit;

	if (number >= 10)
		ft_putnbr(number / 10);
	digit = (number % 10) + '0';
	write(1, &digit, 1);
}
