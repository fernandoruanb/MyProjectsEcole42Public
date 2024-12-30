/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:38:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/29 16:42:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_next_number(t_stack *stack)
{
	int	index;

	index = 0;
	while (index < stack->elements_b)
	{
		if (stack->stack_b[index] < stack->stack_a[0])
			return (index);
		index++;
	}
	return (index);
}
