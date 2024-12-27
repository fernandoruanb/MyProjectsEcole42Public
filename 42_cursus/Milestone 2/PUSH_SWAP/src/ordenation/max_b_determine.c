/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_b_determine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:35:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/27 12:46:05 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	max_b_determine(t_stack *stack)
{
	int	max;
	int	index;

	index = 0;
	max = stack->stack_b[0];
	while (index < stack->elements_b)
	{
		if (stack->stack_b[index] > max)
			max = stack->stack_b[index];
		index++;
	}
	return (max);
}
