/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_numbers_generic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/03 14:39:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_target_index(t_stack *stack, int target_number)
{
	int	index;

	index = 0;
	while (stack->stack_b[index] != target_number
		&& index < stack->elements_b)
		index++;
	return (index);
}

static int	find_best_match_b(t_stack *stack)
{
	int		index;
	long	match;

	match = LONG_MIN;
	if (stack->stack_a[0] > stack->max_b
		|| stack->stack_a[0] < stack->min_b)
		match = max_b_determine(stack);
	else
	{
		index = 0;
		while (index < stack->elements_b)
		{
			if (stack->stack_b[index] > match
				&& stack->stack_b[index]
				< stack->stack_a[0])
				match = stack->stack_b[index];
			index++;
		}
	}
	return ((int)match);
}

static void	sort_b(t_stack *stack)
{
	int	target_number;
	int	index;
	int	moves;

	target_number = find_best_match_b(stack);
	index = find_target_index(stack, target_number);
	moves = get_least_moves_b(stack, index);
	if (moves)
	{
		while (stack->stack_b[0] != target_number)
			ft_rrb(stack, 1);
	}
	else if (moves == 0)
	{
		while (stack->stack_b[0] != target_number)
			ft_rb(stack, 1);
	}
	ft_pb(stack, 1);
}

void	high_numbers_generic(t_stack *stack)
{
	if (stack->size_a == 4)
		ft_pb(stack, 1);
	else if (stack->size_a >= 5)
	{
		ft_pb(stack, 1);
		ft_pb(stack, 1);
	}
	while (stack->size_a > 3)
	{
		stack->max_b = max_b_determine(stack);
		stack->min_b = min_b_determine(stack);
		sort_b(stack);
	}
	three_elements(stack);
	stack->max_b = max_b_determine(stack);
	if (stack->stack_b[0] != stack->max_b)
		max_b_to_top(stack);
	if (check_sorted_b(stack))
		ft_printf("YES!!!\n");
	sort_a(stack);
}
