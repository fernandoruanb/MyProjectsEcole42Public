/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_match.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:04:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/03 19:47:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_best_match_b(t_stack *stack)
{
	int		index;
	long	match;
	long	target;

	target = LONG_MIN;
	if (stack->stack_a[0] > stack->max_b
		|| stack->stack_a[0] < stack->min_b)
		match = find_location_max_b(stack);
	else
	{
		index = 0;
		while (index < stack->elements_b)
		{
			if (stack->stack_b[index] > target
				&& stack->stack_b[index]
				< stack->stack_a[0])
			{
				target = stack->stack_b[index];
				match = index;
			}
			index++;
		}
	}
	return ((int)match);
}
