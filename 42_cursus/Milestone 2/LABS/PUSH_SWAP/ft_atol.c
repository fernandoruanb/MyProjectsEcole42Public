/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:25:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 10:29:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int		index;
	long	result;
	long	signal;

	index = 0;
	result = 0;
	signal = 1;
	while (nptr[index] == ' ' || nptr[index] == '\t'
		|| nptr[index] == '\v' || nptr[index] == '\f'
		|| nptr[index] == '\r' || nptr[index] == '\n')
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			signal == -1;
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
