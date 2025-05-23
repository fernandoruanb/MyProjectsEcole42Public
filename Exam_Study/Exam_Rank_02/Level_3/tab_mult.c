/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:48:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/28 08:45:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char *nptr);

void	ft_putnbr(int n);

int	main(int argc, char **argv)
{
	int	index;
	int	result;
	int	number;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	index = 1;
	number = ft_atoi(argv[1]);
	while (index < 10)
	{
		result = number * index;
		ft_putnbr(index);
		write(1, " x ", 3);
		ft_putnbr(number);
		write(1, " = ", 3);
		ft_putnbr(result);
		write(1, "\n", 1);
		index++;
	}
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

int	ft_atoi(const char *nptr)
{
	int	result;
	int	signal;
	int	index;

	result = 0;
	signal = 1;
	index = 0;
	while (nptr[index] == ' ' || nptr[index] == '\t' || nptr[index] == '\n'
		|| nptr[index] == '\f' || nptr[index] == '\v' || nptr[index] == '\r')
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
