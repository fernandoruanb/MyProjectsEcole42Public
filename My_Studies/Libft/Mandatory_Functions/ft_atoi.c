/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:27:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/30 18:41:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	count_signal(char c, int *count, int *signal);

int	ft_atoi(char *nptr);

int	main(int argc, char **argv)
{
	int	result;
	int	result2;

	if (argc < 2)
		return (1);
	result = ft_atoi(argv[1]);
	result2 = atoi(argv[1]);
	printf("(MY FUNCTION) %i.\n", result);
	printf("(ORIGINAL) %i.\n", result2);
	return (0);
}

int	ft_atoi(char *nptr)
{
	int	result;
	int	signal;
	int	index;
	int	count;

	result = 0;
	signal = 1;
	index = 0;
	count = 0;
	while (nptr[index] == ' ' || nptr[index] == '\n' || nptr[index] == '\t'
		|| nptr[index] == '\v' || nptr[index] == '\r' || nptr[index] == '\f')
		index++;
	while (nptr[index] == '-' || nptr[index] == '+')
	{
		count_signal(nptr[index], &count, &signal);
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

static void	count_signal(char c, int *signal, int *count)
{
	if (c == '-' && *count == 0)
		*signal = -1;
	(*count)++;
	if (*count > 1)
		*signal = 0;
}
