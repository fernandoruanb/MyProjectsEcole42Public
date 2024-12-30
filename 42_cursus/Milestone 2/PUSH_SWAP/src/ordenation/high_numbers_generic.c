/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_numbers_generic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/29 17:26:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*static void	organize_stack_a(t_stack *stack)
{
	three_elements(stack);
	while (stack->elements_b != 13)
	{
		if (stack->stack_b[0] < stack->stack_a[0] &&
			(stack->stack_b[0] > stack->stack_a[stack->size_a - 1])
			ft_pa(stack, 1);
		else
			ft_rra(stack, 1);
	}
}*/

/*static void	max_b_to_top(t_stack *stack)
{
	int	index;
	int	moves;

	index = 0;
	stack->max_b = max_b_determine(stack);
	while (stack->stack_b[index] != stack->max_b)
		index++;
	moves = get_least_moves_b(stack, index);
	if (moves)
	{
		while (stack->stack_b[0] != stack->max_b)
			ft_rb(stack, 1);
	}
	else if (moves == 0)
	{
		while (stack->stack_b[0] != stack->max_b)
			ft_rrb(stack, 1);
	}
}*/

static void	sort_stack_b(t_stack *stack)
{
	int	index;
	int	moves;
	int	target;

	if (stack->stack_a[0] > stack->max_b
		|| stack->stack_a[0] < stack->min_b)
	{
		index = find_location_max_b(stack);
		moves = get_least_moves_b(stack, index);
		target = stack->max_b;
		choose_best_movement(stack, target, moves);
	}
	else if (stack->stack_a[0] < stack->max_b
			&& stack->stack_a[0] > stack->min_b)
	{
		while (1)
		{
			if (stack->stack_a[0] < stack->stack_b[0]
				&& stack->stack_a[0] 
				> stack->stack_b[stack->elements_b - 1])
				break ;
			ft_rrb(stack, 1);
		}
		ft_pb(stack, 1);
	}
}

void	high_numbers_generic(t_stack *stack)
{
	ft_pb(stack, 1);
	ft_pb(stack, 1);
	//while (stack->size_a != 10)
	//{
		stack->max_b = max_b_determine(stack);
		stack->min_b = min_b_determine(stack);
		sort_stack_b(stack);
	//}
	//max_b_to_top(stack);
	//organize_stack_a(stack);
}
