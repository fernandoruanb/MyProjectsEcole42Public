/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:46:16 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 12:47:03 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	complete_faults(t_stack *stack, int n_a, int n_b)
{
	while (stack->stack_a[0] != n_a)
		ft_rra(stack, 1);
	while (stack->stack_b[0] != n_b)
		ft_rrb(stack, 1);
}

int	check_rrr(t_stack *stack)
{
	int	number_a;
	int	number_b;

	number_a = stack->stack_a[stack->index_a];
	number_b = stack->stack_b[stack->index_b];
	if (get_rotates_cost(stack, stack->index_a, 'a') < stack->index_a)
	{
		if (get_rotates_cost(stack, stack->index_b, 'b') < stack->index_b)
		{
			while (stack->stack_a[0] != number_a
				&& stack->stack_b[0] != number_b)
				ft_rrr(stack);
			complete_faults(stack, number_a, number_b);
			return (1);
		}
	}
	return (0);
}
