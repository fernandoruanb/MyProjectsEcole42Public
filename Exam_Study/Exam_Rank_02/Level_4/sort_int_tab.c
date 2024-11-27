/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:44:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/11/27 17:59:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size);

int	main(int argc, char **argv)
{
	int	tab[] = {0, 2, -3, 5, 42, 12, 60, 1};
	int	len;
	int	index;

	len = 8;
	sort_int_tab(tab, 8);
	index = 0;
	while (index < len)
	{
		if (index < len - 1)
			printf("%d, ", tab[index]);
		else
			printf("%d.\n", tab[index]);
		index++;
	}
	return (0);
}

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
