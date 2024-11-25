/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:22:27 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/25 17:29:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int *tab, unsigned int len);

int	main(void)
{
	int	tab[] = {9, 2, 90, 30, -2, 42};
	int	result;

	result = max(tab, 5);
	printf("%d\n", result);	
	return (0);
}

int	max(int *tab, unsigned int len)
{
	int	max;
	int	index;

	index = 0;
	max = tab[index];
	while (index < len)
	{
		if (max < tab[index])
			max = tab[index];
		index++;
	}
	return (max);
}
