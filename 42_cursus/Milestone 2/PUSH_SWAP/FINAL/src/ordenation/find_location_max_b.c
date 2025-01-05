/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_location_max_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:21:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 10:19:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_location_max_b(t_stack *stack)
{
	int	index;

	index = 0;
	stack->max_b = max_b_determine(stack);
	while (stack->stack_b[index] != stack->max_b
		&& index < stack->size_a)
		index++;
	while (stack->stack_b[index] != stack->max_b)
		index++;
	return (index);
}
