/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_location_max_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 19:27:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/03 19:48:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_location_max_a(t_stack *stack, int max)
{
	int	index;

	index = 0;
	while (stack->stack_a[index] != max
		&& index != stack->size_a)
		index++;
	return (index);
}
