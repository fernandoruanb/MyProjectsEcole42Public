/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_location_max_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:21:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/30 12:33:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_location_max_b(t_stack *stack)
{
	int	index;

	index = 0;
	stack->max_b = max_b_determine(stack);
	while (stack->stack_b[index] != stack->max_b
		&& stack->stack_b[index] <= stack->size_a)
		index++;
	return (index);
}
