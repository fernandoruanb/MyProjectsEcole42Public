/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:31:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/21 15:44:20 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr(int n);

static int	is_prime(int num);

static int	ft_atoi(const char *nptr);

int	main(int argc, char **argv)
{	
	int	num;
	int	sum;
	int	total;

	if (argc < 2 || argc > 2)
	{
		write(1, "0\n", 2);
		return (1);
	}
	num = ft_atoi(argv[1]);
	if (num <= 0)
		write(1, "0\n", 2);
	total = 0;
	while (num > 0)
	{
		if (is_prime(num))
			total += num;
		num--;
	}
	ft_putnbr(total);
	write(1, "\n", 1);
	return (0);
}

static int	ft_atoi(const char *nptr)
{
	int	index;
	int	result;
	int	signal;

	index = 0;
	signal = 1;
	result = 0;
	while (nptr[index] == ' ' || nptr[index] == '\n' || nptr[index] == '\t'
		|| nptr[index] == '\r' || nptr[index] == '\v' || nptr[index] == '\f')
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			signal *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result *= 10;
		result += nptr[index] - '0';
		index++;
	}
	return (result * signal);
}

static int	is_prime(int num)
{
	int	attempt;

	if (num <= 1)
		return (0);
	attempt = 2;
	while (attempt * attempt <= num)
	{
		if (num % attempt == 0)
			return (0);
		attempt++;
	}
	return (1);
}

static void	ft_putnbr(int n)
{
	long	number;
	char	digit;

	number = n;
	if (number < 0)
	{
		write (1, "-", 1);
		number = -n;
	}
	if (number >= 10)
		ft_putnbr(number / 10);
	digit = (number % 10) + '0';
	write(1, &digit, 1);
}
