/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:24:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/23 12:30:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	lcm(unsigned int a, unsigned int b);

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 3)
		return (1);
	result = lcm(atoi(argv[1]), atoi(argv[2]));
	printf("O MMC é: %d\n", result);
	return (0);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	start;

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
