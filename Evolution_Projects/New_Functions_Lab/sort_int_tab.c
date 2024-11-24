/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:45:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/24 13:14:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size);

int	main(void)
{
	int	tab[] = {0, 4, 5, 1, 2};
	int	index;

	sort_int_tab(tab, 5);
	index = 0;
	while (index < 5)
	{
		if (index < 5 - 1)
			printf("%d, ", tab[index]);
		else
			printf("%d.\n", tab[index]);
		index++;
	}
	return (0);
}*/

void	sort_int_tab(int *tab, unsigned int size)
{
	int	index;
	int	temp;

	index = 0;
	while (index < (size - 1))
	{
		if (tab[index] > tab[index + 1])
		{
			temp = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = temp;
			index = 0;
		}
		else
			index++;
	}
}
