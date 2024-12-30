/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_numbers_generic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/30 12:55:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void     max_b_to_top_operation(t_stack *stack)
{
	int     index;
	int     moves;

	index = find_location_max_b(stack);
	moves = get_least_moves_b(stack, index);
        choose_best_movement(stack, stack->max_b, moves);
}

static void	max_b_to_top(t_stack *stack)
{
	int	index;
	int	moves;
	
	index = find_location_max_b(stack);
	moves = get_least_moves_b(stack, index);
	if (moves == 1)
	{
		while (stack->stack_b[0] != stack->max_b)
			ft_rb(stack, 1);
	}
	else if (moves == 0)
	{
		while (stack->stack_b[0] != stack->max_b)
			ft_rrb(stack, 1);
	}
}

/*static void	organize_stack_a(t_stack *stack)
{
	//while (stack->elements_b != 0)
	//{
		if (stack->stack_a[stack->size_a - 1]
			> stack->stack_b[0])
			ft_rra(stack, 1);
		else if ((stack->stack_a[0] > stack->stack_b[0]
			&& stack->stack_a[stack->size_a - 1]
			< stack->stack_b[0]))
			ft_pa(stack, 1);
	//}
}*/

static void	sort_stack_b(t_stack *stack)
{
	if (stack->stack_a[0] > stack->max_b
		|| stack->stack_a[0] < stack->min_b)
	{
		if (stack->elements_b == 2
			&& stack->stack_b[0] != stack->max_b)
		{
			ft_sb(stack, 1);
			ft_pb(stack, 1);
			return ;
		}
		max_b_to_top_operation(stack);
	}
	else
	{
		while (!(stack->stack_a[0] > stack->stack_b[0]
				&& stack->stack_a[0]
				< stack->stack_b[stack->elements_b - 1]))
			ft_rb(stack, 1);
		ft_pb(stack, 1);
	}
}

void	high_numbers_generic(t_stack *stack)
{
	int	sorted_b;

	ft_pb(stack, 1);
	ft_pb(stack, 1);
	while (stack->size_a != 3)
	{
		stack->max_b = max_b_determine(stack);
		stack->min_b = min_b_determine(stack);
		sort_stack_b(stack);
	}
	three_elements(stack);
	max_b_to_top(stack);
	sorted_b = check_sorted_b(stack);
	if (sorted_b == 1)
		ft_printf("YES!!!!\n");
	/*stack->max_b = max_b_determine(stack);
	stack->min_b = min_b_determine(stack);
	organize_stack_a(stack);*/
}
