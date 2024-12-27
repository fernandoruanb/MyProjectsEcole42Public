/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_numbers_generic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/27 20:04:35 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*static void	push_all_b_to_a(t_stack *stack)
{
	while (stack->elements_b > 0)
		ft_pa(stack, 1);
}*/

static void	organize_median_b(t_stack *stack, int median)
{
	int	count;
	int	index;

	index = 0;
	count = stack->size_a;
	while (count > 0)
	{
		if (stack->stack_a[index] < median)
			ft_pb(stack, 1);
		else
			ft_ra(stack, 1);
		count--;
	}
}

void	high_numbers_generic(t_stack *stack)
{
	int	median;
	int	even_odd;
	int	size;
	int	*tab;
	int	index;

	index = 0;
	tab = (int *)malloc(stack->size_a * sizeof(int));
	if (!tab)
		return ;
	while (index < stack->size_a)
	{
		tab[index] = stack->stack_a[index];
		index++;
	}
	size = stack->size_a;
	tab = sort_int_tab(tab, stack->size_a);
	even_odd = stack->size_a % 2;
	if (even_odd == 1)
		median = tab[size / 2];
	else
		median = (tab[size / 2] + tab[(size / 2) + 1]) / 2;
	organize_median_b(stack, median);
	free(tab);
	ft_printf("MEDIAN HERE: %d!\n", median);
}
