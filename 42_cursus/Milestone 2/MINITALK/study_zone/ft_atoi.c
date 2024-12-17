/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:06:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/17 11:18:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	index;
	int	result;
	int	signal;

	index = 0;
	result = 0;
	signal = 1;
	while (nptr[index] == ' ' || nptr[index] == '\n' || nptr[index] == '\t'
		|| nptr[index] == '\r' || nptr[index] == '\v' || nptr[index] == '\f')
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
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
	return (result * signal);
}

/*int	main(int argc, char **argv)
{
	int	result;

	if (argc != 2)
		return (1);
	result = ft_atoi(argv[1]);
	printf("Result: %d\n", result);
	return (0);
}*/
