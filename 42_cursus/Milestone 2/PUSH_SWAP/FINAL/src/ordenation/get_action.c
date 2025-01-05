/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:16:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 15:56:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	get_action(t_stack *stack)
{
	int		number_a;
	int		number_b;

	number_a = stack->stack_a[stack->index_a];
	number_b = stack->stack_b[stack->index_b];
	if (get_rotates_cost(stack, stack->index_a, 'a') == stack->index_a)
	{
		while (stack->stack_a[0] != number_a)
			ft_ra(stack, 1);
	}
	else
	{
		while (stack->stack_a[0] != number_a)
			ft_rra(stack, 1);
	}
	if (get_rotates_cost(stack, stack->index_b, 'b') == stack->index_b)
	{
		while (stack->stack_b[0] != number_b)
			ft_rb(stack, 1);
	}
	else
	{
		while (stack->stack_b[0] != number_b)
			ft_rrb(stack, 1);
	}
}
