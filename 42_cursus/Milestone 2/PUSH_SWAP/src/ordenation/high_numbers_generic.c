/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_numbers_generic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/29 08:20:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	decide_movement(t_stack *stack)
{
	int	index;

	if (stack->stack_a[0] > stack->max_b)
	{
		index = locate_max_b;
	}
}

void	high_numbers_generic(t_stack *stack)
{
	ft_pb(stack, 1);
	ft_pb(stack, 1);
	stack->max_b = max_b_determine(stack);
	stack->min_b = min_b_determine(stack);
	while (stack->size_a != 3)
		decide_movement(stack);
	ft_printf("MAX: %d AND MIN: %d\n", stack->max_b, stack->min_b);
}
