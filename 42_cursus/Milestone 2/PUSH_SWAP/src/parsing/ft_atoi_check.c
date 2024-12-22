/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:34:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/22 10:04:36 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_limit(long result, int sig, int *error)
{
	if (result < INT_MIN || result > INT_MAX)
	{
		*error = 1;
		return (ft_putendl_fd_0("INT_MIN/MAX Error.", 2));
	}
	else
		return ((int)(result * sig));
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
