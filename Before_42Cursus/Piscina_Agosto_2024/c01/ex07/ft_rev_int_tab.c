/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:55:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/08/19 15:55:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	temp;

	index = 0;
	while (index < size / 2)
	{
		temp = tab[index];
		tab[index] = tab[size - index - 1];
		tab[size - index - 1] = temp;
		index++;
	}
}
//int	main(void)
//{
//	int	arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int	index = 0;
//
//	ft_rev_int_tab(arr, 10);
//	while (index < 10)
//	{
//		printf("%i ", arr[index]);
//		index++;
//	}
//}
// Caro avaliador, não se esqueça de colocar o <stdio.h>.
