/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_n1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:58:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 18:21:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_smallest_n1(t_stack *stack, int *index)
{
	int	target_number;
	int	flag;

	target_number = stack->stack_a[0];
	flag = 0;
	while (*index < stack->size_a - 1)
	{
		if (target_number > stack->stack_a[*index])
		{
			target_number = stack->stack_a[*index];
			flag = *index;
			*index = 0;
		}
		(*index)++;
	}
	*index = flag;
}
