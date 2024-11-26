/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:05:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/26 18:04:33 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_hex(int number);

int	ft_atoi(const char *nptr);

int	main(int argc, char **argv)
{
	int	number;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	number = ft_atoi(argv[1]);
	print_hex(number);
	write(1, "\n", 1);
	return (0);
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
		|| nptr[index] == '\f' || nptr[index] == '\r')
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
		result += (nptr[index] - '0');
		index++;
	}
	return (result * signal);
}

void	print_hex(int number)
{
	char	*hex_digits;
	char	digit;

	hex_digits = "0123456789abcdef";
	if (number >= 16)
		print_hex(number / 16);
	digit = hex_digits[number % 16];
	write(1, &digit, 1);
}
