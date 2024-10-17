/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:16:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/10/17 13:16:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb);

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 2)
		return (1);
	result = ft_iterative_factorial(atoi(argv[1]));
	printf("(MY FUNCTION) %i.\n", result);
	return (0);
}*/

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	count;

	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	result = nb;
	count = nb - 1;
	while (count > 1)
	{
		result *= count;
		count--;
	}
	return (result);
}
