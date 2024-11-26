/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:09:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/26 13:25:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

unsigned int	lcm(unsigned int a, unsigned int b);

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 3 || argc > 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	result = lcm(atoi(argv[1]), atoi(argv[2]));
	printf("%d\n", result);
	return (0);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int	start;

	if (a > b)
		start = a;
	else
		start = b;
	while (1)
	{
		if (start % a == 0 && start % b == 0)
			break ;
		start++;
	}
	return (start);
}
