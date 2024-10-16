/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:45:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/16 15:45:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>

void	ft_swap(int *a, int *b);

int	main(int argc, char **argv)
{
	int	number;
	int	number2;

	if (argc < 3)
		return (1);
	number = atoi(argv[1]);
	number2 = atoi(argv[2]);
	printf("Os números eram: %i e %i.\n", number, number2);
	ft_swap(&number, &number2);
	printf("(MY FUNCTION) %i e %i.\n", number, number2);
	return (0);
}*/

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
