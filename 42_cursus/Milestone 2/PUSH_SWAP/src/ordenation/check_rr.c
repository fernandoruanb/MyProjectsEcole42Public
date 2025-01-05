/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:22:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 11:27:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_rr(t_stack *stack)
{
	int	number_a;

	number_a = stack->stack_a[stack->index_a];
	if (get_rotates_cost(stack, stack->index_a, 'a') == stack->index_a)
	{
		if (get_rotates_cost(stack, stack->index_b, 'b') == stack->index_b)
		{
			if (stack->index_a == stack->index_b)
			{
				while (number_a != stack->stack_a[0])
					ft_rr(stack);
				return (1);
			}
		}
	}
	return (0);
}
