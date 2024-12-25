/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_n2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:19:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 19:00:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_smallest_n2(t_stack *stack, int *index, int flag)
{
	int	last_number;
	int	target_number;

	target_number = stack->stack_a[0];
	while (*index < stack->size_a - 1)
	{
		if (target_number > stack->stack_a[*index])
		{
			if (*index == flag)
				(*index)++;
			last_number = target_number;
			target_number = stack->stack_a[*index];
			*index = 0;
		}
		(*index)++;
	}
}
