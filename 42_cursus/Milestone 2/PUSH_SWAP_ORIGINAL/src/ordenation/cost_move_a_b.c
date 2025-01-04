/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_move_a_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:09:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/03 14:32:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	set_target_b(t_stack *stack, int n)
{
	long	match;
	int	index;

	match = LONG_MIN;
	stack->max_b = max_b_determine(stack);
	stack->min_b = min_b_determine(stack);
	if (stack->stack_a[n] > stack->max_b
		|| stack->stack_a[n] < stack->min_b)
		return (find_location_max_b(stack));
	else
	{
		index = 0;
		while (index < stack->elements_b)
		{
			if (stack->stack_b[index] > match &&
				stack->stack_b[index]
				< stack->stack_a[n])
				match = stack->stack_b[index];
			index++;
		}
	}
	return (match);
}

void	cost_move_a_b(t_stack *stack)
{
	int	target_index;
	int	index;
	int	total;

	index = 0;
	stack->push_cost = INT_MAX;
	while (index < stack->size_a)
	{
		stack->cost_a = get_rotates_cost(stack, index, 'a');
		target_index = set_target_b(stack, index);
		stack->cost_b = get_rotates_cost(stack, target_index, 'b');
		total = stack->cost_a + stack->cost_b;
		if (total < stack->push_cost)
		{
			stack->push_cost = total;
			stack->index_a = index;
			stack->index_b = target_index;
		}
		index++;
	}
	stack->push_cost++;
	ft_printf("Best push_cost: %d\n", stack->push_cost);
	ft_printf("Best index stack A: %d\n", stack->index_a);
	ft_printf("Best target stack B: %d\n", stack->index_b);
}
