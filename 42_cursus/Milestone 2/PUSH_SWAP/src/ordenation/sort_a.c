/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:45:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 19:24:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_target_index(t_stack *stack, int target_number)
{
	int	index;

	index = 0;
	while (stack->stack_a[index] != target_number
		&& index < stack->size_a)
		index++;
	return (index);
}

static int	find_min_a(t_stack *stack)
{
	long	min;
	int	index;

	min = LONG_MAX;
	index = 0;
	while (index < stack->size_a)
	{
		if (stack->stack_a[index] < min)
			min = stack->stack_a[index];
		index++;
	}
	return ((int)min);
}

static int	set_target_a(t_stack *stack)
{
	long	match;
	int	index;

	match = LONG_MIN;
	index = 0;
	while (index < stack->size_a)
	{
		if (stack->stack_b[0] < stack->stack_a[index]
			&& stack->stack_a[index] > match)
			match = stack->stack_a[index];
		index++;
	}
	if (match == LONG_MIN)
		match = find_min_a(stack);
	return (match);
}

void	sort_a(t_stack *stack)
{
	int	target_number;
	int	index;
	int	moves;
	int	diviser_line;

	while (stack->elements_b > 0)
	{
		diviser_line = stack->size_a / 2;
		target_number = set_target_a(stack);
		index = find_target_index(stack, target_number);
		moves = get_least_moves(stack, &index);
		if (index > diviser_line)
		{
			while (stack->stack_a[index] != target_number)
				ft_rra(stack, 1);
		}
		else
		{
			while (stack->stack_a[0] != target_number)
				ft_ra(stack, 1);
		}
		ft_pa(stack, 1);
	}
}
