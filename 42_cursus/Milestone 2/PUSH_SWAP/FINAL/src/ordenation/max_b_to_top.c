/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_b_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:35:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/04 16:55:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	max_b_to_top(t_stack *stack)
{
	int	index;
	int	moves;

	index = 0;
	stack->max_b = max_b_determine(stack);
	while (stack->stack_b[index] != stack->max_b)
		index++;
	moves = get_least_moves_b(stack, index);
	if (moves == 1)
	{
		while (stack->stack_b[0] != stack->max_b)
			ft_rrb(stack, 1);
	}
	else if (moves == 0)
	{
		while (stack->stack_b[0] != stack->max_b)
			ft_rb(stack, 1);
	}
}
