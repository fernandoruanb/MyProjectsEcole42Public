/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_b_determine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:38:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/27 12:43:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	min_b_determine(t_stack *stack)
{
	int	min;
	int	index;

	min = stack->stack_b[0];
	index = 0;
	while (index < stack->elements_b)
	{
		if (stack->stack_b[index] < min)
			min = stack->stack_b[index];
		index++;
	}
	return (min);
}
