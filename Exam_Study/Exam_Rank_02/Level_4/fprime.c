/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:55:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/27 11:04:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	fprime(int number);

int	main(int argc, char **argv)
{
	int	number;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	number = atoi(argv[1]);
	if (number == 1)
	{
		write(1, "1", 1);
		return (0);
	}
	fprime(number);
	return (0);
}

void	fprime(int number)
{
	int	index;

	index = 1;
	while (number >= ++index)
	{
		if (number % index == 0)
		{
			printf("%d", index);
			if (number == index)
				break ;
			printf("*");
			number /= index;
			index = 1;
		}
	}
	printf("\n");
}
