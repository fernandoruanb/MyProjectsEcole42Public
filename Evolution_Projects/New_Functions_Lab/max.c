/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:36:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/20 15:50:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*int	max(int *tab, unsigned int len);

int	main(void)
{
	unsigned int	len;
	int				tab[] = {0, 1, 2, 3, 4, 5, 42};
	int				result;

	len = 7;
	result = max(tab, len);
	printf("%d\n", result);
	return (0);
}*/

int	max(int *tab, unsigned int len)
{
	int				result;
	unsigned int	index;

	if (len == 0)
		return (0);
	index = 0;
	result = 0;
	while (index < len)
	{
		if (tab[index] > result)
			result = tab[index];
		index++;
	}
	return (result);
}
