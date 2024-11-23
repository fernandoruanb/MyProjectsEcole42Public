/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:07:49 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/23 13:17:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	nbr1;
	int	nbr2;

	nbr1 = atoi(argv[1]);
	nbr2 = atoi(argv[2]);
	if (nbr1 > 0 && nbr2 > 0)
	{
		while (nbr1 != nbr2)
		{
			if (nbr1 > nbr2)
				nbr1 -= nbr2;
			else
				nbr2 -= nbr1;
		}
	}
	printf("O MDC é: %d\n", nbr1);
	return (0);
}
