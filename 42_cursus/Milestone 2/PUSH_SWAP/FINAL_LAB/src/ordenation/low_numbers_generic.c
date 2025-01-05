/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_numbers_generic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/26 18:41:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_all_b_to_a(t_stack *stack)
{
	while (stack->elements_b > 0)
		ft_pa(stack, 1);
}

void	low_numbers_generic(t_stack *stack)
{
	int	counter;
	int	second_counter;
	int	first;

	first = 0;
	counter = stack->size_a;
	while (counter != 6)
	{
		find_smallest_num(stack, &first);
		if (move_to_b(stack, &first) == 1)
		{
			push_all_b_to_a(stack);
			return ;
		}
		counter--;
		first = 0;
	}
	six_elements(stack);
	second_counter = stack->elements_b;
	while (second_counter != 0)
	{
		ft_pa(stack, 1);
		second_counter--;
	}
}
