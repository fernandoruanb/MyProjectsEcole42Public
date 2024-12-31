/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_biggest_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:44:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/31 19:55:59 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	closest_biggest_a(t_stack *stack)
{
	int	index;
	int	top_b;

	index = 0;
	top_b = stack->stack_b[0];
	while (index < stack->size_a)
	{
		if (stack->stack_a[index] > top_b)
			return (index);
		index++;
	}
	return (-1);
}
