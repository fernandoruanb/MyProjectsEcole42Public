/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:35:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/05 14:35:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>*/

int	*ft_range(int min, int max);

/*int	main(void)
{
	int	*result;
	int	min;
	int	max;
	int	size;
	int	index;

	max = 100;
	min = 0;
	size = max - min;
	result = ft_range(min, max);
	index = 0;
	while (index < size)
	{
		if (index < size - 1)
			printf("%i, ", result[index]);
		else
			printf("%i.\n", result[index]);
		index++;
	}
	return (0);
}
*/
int	*ft_range(int min, int max)
{
	int	size;
	int	index;
	int	*numbers;

	if (min >= max)
		return (NULL);
	size = max - min;
	index = 0;
	numbers = (int *)malloc(size * 4);
	while (index < size)
	{
		numbers[index] = min;
		min++;
		index++;
	}
	return (numbers);
}
