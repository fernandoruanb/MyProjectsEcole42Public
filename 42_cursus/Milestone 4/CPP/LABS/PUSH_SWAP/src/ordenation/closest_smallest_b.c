/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_smallest_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:26:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/31 18:57:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	closest_smallest_b(t_stack *stack)
{
	int	top_a;
	int	index;

	top_a = stack->stack_a[0];
	index = 0;
	while (index < stack->elements_b)
	{
		if (stack->stack_b[index] < top_a)
			return (index);
		index++;
	}
	return (-1);
}
