/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:56:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/23 14:16:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int n);

int		ft_atoi(char *nptr);

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

int	ft_atoi(char *nptr)
{
	int	result;
	int	signal;
	int	index;

	result = 0;
	signal = 1;
	index = 0;
	while (nptr[index] == ' ' || nptr[index] == '\n'
		|| nptr[index] == '\t' || nptr[index] == '\v'
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

void	print_hex(int n)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}
