/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:23:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/26 16:37:58 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	result;
	int	nbr1;
	int	nbr2;

	if (argc < 2 || argc > 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	nbr1 = atoi(argv[1]);
	nbr2 = atoi(argv[2]);
	while (nbr1 != nbr2)
	{
		if (nbr1 > nbr2)
			nbr1 -= nbr2;
		else
			nbr2 -= nbr1;
	}
	printf("%d\n", nbr1);
	return (0);
}
