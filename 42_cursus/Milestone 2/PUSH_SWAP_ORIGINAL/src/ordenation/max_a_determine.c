/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_a_determine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:22:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/30 15:28:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	max_a_determine(t_stack *stack)
{
	int	max;
	int	index;

	index = 0;
	max = stack->stack_a[0];
	while (index < stack->size_a)
	{
		if (stack->stack_a[index] > max)
			max = stack->stack_a[index];
		index++;
	}
	return (max);
}
