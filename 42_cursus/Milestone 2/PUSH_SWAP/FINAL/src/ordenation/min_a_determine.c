/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_a_determine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:21:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/03 09:42:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	min_a_determine(t_stack *stack)
{
	long	min;
	int		index;

	min = LONG_MAX;
	index = 0;
	while (index < stack->size_a)
	{
		if (stack->stack_a[index] < min)
			min = stack->stack_a[index];
		index++;
	}
	return ((int)min);
}
