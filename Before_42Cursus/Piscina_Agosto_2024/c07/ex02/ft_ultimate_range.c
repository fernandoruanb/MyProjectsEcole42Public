/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:55:21 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/05 14:55:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

int	ft_ultimate_range(int **range, int min, int max);

/*int	main(void)
{
	int	*numbers;
	int	min;
	int	max;
	int	size;

	min = 0;
	max = 5;
	size = ft_ultimate_range(&numbers, min, max);
	printf("O resultado ficou: %i\n", size);
	return (0);
}
*/
int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	index;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(size * 4);
	index = 0;
	while (index < size)
	{
		(*range)[index] = min;
		min++;
		index++;
	}
	return (size);
}
