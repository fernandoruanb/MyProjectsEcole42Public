/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_high_numbers_generic_v2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:09:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 11:53:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	init_cost(t_stack *stack)
{
	stack->push_cost = INT_MAX;
	stack->cost_a = 0;
	stack->cost_b = 0;
	stack->index_a = 0;
	stack->index_b = 0;
}

static int	get_target_b(t_stack *stack, int number)
{
	long	match;
	int		target_b;
	int		index;

	match = LONG_MIN;
	if (stack->stack_a[number] > stack->max_b
		|| stack->stack_a[number] < stack->min_b)
		return (find_location_max_b(stack));
	index = 0;
	while (index < stack->elements_b)
	{
		if (stack->stack_b[index] > match
			&& stack->stack_b[index]
			< stack->stack_a[number])
		{
			match = stack->stack_b[index];
			target_b = index;
		}
			index++;
	}
	return (target_b);
}

static void	find_low_cost(t_stack *stack)
{
	int	index;
	int	target_index;

	init_cost(stack);
	index = 0;
	while (index < stack->size_a)
	{
		stack->cost_a = get_rotates_cost(stack, index, 'a');
		target_index = get_target_b(stack, index);
		ft_printf("MAX B: %d | MIN B: %d\n", stack->max_b, stack->min_b);
		ft_printf("O index A %d tem o target index é: %d\n", index, target_index);
		stack->cost_b = get_rotates_cost(stack, target_index, 'b');
		if (stack->cost_a + stack->cost_b + 1 < stack->push_cost)
		{
			stack->push_cost = stack->cost_a + stack->cost_b + 1;
			stack->index_a = index;
			stack->index_b = target_index;
		}
		index++;
	}
	ft_printf("Push, index_a e index_b: %d %d %d\n", stack->push_cost, stack->index_a, stack->index_b);
	ft_printf("Cost A e Cost B: %d %d\n", stack->cost_a, stack->cost_b);
}

void	new_high_numbers_generic_v2(t_stack *stack)
{
	if (check_pre_sorted(stack))
		return ;
	if (stack->size_a == 4)
		ft_pb(stack, 1);
	else if (stack->size_a >= 5)
	{
		ft_pb(stack, 1);
		ft_pb(stack, 1);
	}
	while (stack->size_a != 3)
	{
		stack->max_b = max_b_determine(stack);
		stack->min_b = min_b_determine(stack);
		find_low_cost(stack);
		show_stacks(stack, 'a');
		show_stacks(stack, 'b');
		if (!check_rr(stack))
		{
			if (!check_rrr(stack))
				get_action(stack);
		}
		ft_pb(stack, 1);
	}
	show_stacks(stack, 'b');
	three_elements(stack);
	max_b_to_top(stack);
	if (check_sorted_b(stack))
		ft_printf("YES!!!\n");
	sort_a(stack);
}
