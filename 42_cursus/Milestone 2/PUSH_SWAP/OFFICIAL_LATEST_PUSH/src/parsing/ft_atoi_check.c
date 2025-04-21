/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:34:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/21 10:50:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_valid_limit(long result, int sig, int *error)
{
	long	signed_result;

	signed_result = result * (long)sig;
	if (signed_result < (long)INT_MIN || signed_result > (long)INT_MAX)
	{
		*error = 1;
		return (0);
	}
	else
		return ((int)signed_result);
}

int	ft_atoi_check(const char *nptr, int *error)
{
	int		index;
	long	result;
	int		signal;

	index = 0;
	result = 0;
	signal = 1;
	while (nptr[index] == ' ' || nptr[index] == '\t' || nptr[index] == '\n'
		|| nptr[index] == '\r' || nptr[index] == '\v' || nptr[index] == '\f')
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			signal = -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result *= 10;
		result += (nptr[index] - '0');
		if (result > INT_MAX || result < INT_MIN)
			*error = 1;
		index++;
	}
	return (is_valid_limit(result, signal, error));
}

/*int	main(int argc, char **argv)
{
	long	result;

	if (argc != 2)
	{
		printf("How to use: [INT_NUMBER].\n");
		return (1);
	}
	result = ft_atoi_check(argv[1]);
	printf("The number is: %ld\n", result);
	return (0);
}*/
