/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:46:11 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/22 10:04:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static char	to_lower(char c);

static int	get_digit(char c, int str_base);

int			ft_atoi_base(const char *str, int str_base);

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 3)
		return (1);
	result = ft_atoi_base(argv[1], atoi(argv[2]));
	printf("%d\n", result);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	signal;
	int	digit;

	result = 0;
	signal = 1;
	digit = 0;
	if (!str || str_base < 2 || str_base > 16)
		return (-1);
	if (*str == '-')
	{
		signal *= -1;
		str++;
	}
	while (*str)
	{
		digit = get_digit(*str, str_base);
		if (digit == -1)
			return (-1);
		result = result * str_base + digit;
		str++;
	}
	return (result * signal);
}

static int	get_digit(char c, int str_base)
{
	int	max_digit;

	if (str_base <= 10)
		max_digit = str_base - 1 + '0';
	else
		max_digit = str_base - 10 - 1 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'z' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

static char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
