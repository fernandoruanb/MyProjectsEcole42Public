/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:45:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/04 20:09:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_a(t_stack *stack)
{
	stack->max_b = max_b_determine(stack);
	if (stack->stack_a[2] > stack->max_b)
		ft_rra(stack, 1);
	while (stack->elements_b > 0)
	{
		stack->max_a = max_a_determine(stack);
		stack->min_a = min_a_determine(stack);
		if (stack->stack_a[stack->size_a - 1] > stack->stack_b[0]
			&& stack->stack_a[stack->size_a - 1] != stack->max_a)
			ft_rra(stack, 1);
		else
			ft_pa(stack, 1);
	}
	while (!check_sorted(stack))
		ft_rra(stack, 1);
}
