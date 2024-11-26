/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:27:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/26 11:44:06 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	to_lower(char c);

int	get_digit(char c, int str_base);

int	ft_atoi_base(const char *str, int str_base);

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 3 || argc > 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	result = ft_atoi_base(argv[1], atoi(argv[2]));
	printf("%d\n", result);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	signal;
	int	digit;

	if (str_base < 2 || str_base > 16 || !str)
		return (-1);
	result = 0;
	signal = 1;
	if (*str == '-')
	{
		signal *= -1;
		str++;
	}
	while (*str)
	{
		digit = get_digit(to_lower(*str), str_base);
		if (digit == -1)
			return (-1);
		result *= str_base;
		result += digit;
		str++;
	}
	return (result * signal);
}

int	get_digit(char c, int str_base)
{
	int	max_digit;

	if (str_base < 9)
		max_digit = str_base - 1;
	else
		max_digit = str_base - 11 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'z' && c <= max_digit)
		return (10 + c - 'a');
	return (-1);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
