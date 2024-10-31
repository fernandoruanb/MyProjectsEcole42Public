/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:50:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/19 16:50:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	pass;
	int	index;
	int	temp;

	pass = 0;
	while (pass < size - 1)
	{
		index = 0;
		while (index < size - pass - 1)
		{
			if (tab[index] > tab[index + 1])
			{
				temp = tab[index];
				tab[index] = tab[index + 1];
				tab[index + 1] = temp;
			}
		index++;
		}
	pass++;
	}
}
//int	main(void)
//{
//	int	index = 0;
//	int	arra[10] = {123, 351, 73718, 21, 19, 0, 12, 1, 22, 182838};
//      ft_sort_int_tab(arra, 10);
//
//	while (index < 10)
//	{
//		printf("%i ", arra[index]);
//		index++;
//	}
//	return (0);
//}
