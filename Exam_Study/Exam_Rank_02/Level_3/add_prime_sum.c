/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:41:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/26 09:06:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(const char *nptr);

int		is_prime(int n);

void	ft_putnbr(int n);

int	main(int argc, char **argv)
{
	int	result;
	int	number;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	result = 0;
	number = ft_atoi(argv[1]);
	while (number > 0)
	{
		if (is_prime(number))
			result += number;
		number--;
	}
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}

void	ft_putnbr(int n)
{
	long	num;
	char	digit;

	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr((int)num / 10);
	digit = (num % 10) + '0';
	write(1, &digit, 1);
}

int	is_prime(int n)
{
	int	attempt;

	if (n <= 1)
		return (0);
	attempt = 2;
	while (attempt * attempt <= n)
	{
		if (n % attempt == 0)
			return (0);
		attempt++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	signal;
	int	index;

	result = 0;
	signal = 1;
	index = 0;
	while (nptr[index] == ' ' || nptr[index] == '\n' || nptr[index] == '\t'
		|| nptr[index] == '\v' || nptr[index] == '\f' || nptr[index] == '\r')
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			signal *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result *= 10;
		result += (nptr[index] - '0');
		index++;
	}
	return (result * signal);
}
