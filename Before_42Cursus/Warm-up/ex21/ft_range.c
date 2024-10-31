/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:28:58 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/09/30 19:28:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
//#include <stdio.h>

int	*ft_range(int min, int max);

/*int	main(void)
{
	int	max;
	int	min;
	int	size;
	int	*numbers;
	int	index;

	max = 100;
	min = 0;
	index = 0;
	size = max - min;
	numbers = ft_range(min, max);
	while (index < size)
	{
		if (index < size - 1)
			printf("%i, ", numbers[index]);
		else
			printf("%i.\n", numbers[index]);
		index++;
	}
	return (0);
}*/

int	*ft_range(int min, int max)
{
	int	size;
	int	*numbers;
	int	count;

	if (min >= max)
		return (NULL);
	size = max - min;
	numbers = (int *)malloc(size * 4);
	if (!numbers)
		return (NULL);
	count = 0;
	while (count < size)
	{
		numbers[count] = min;
		min++;
		count++;
	}
	return (numbers);
}
