/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotates_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:09:52 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/04 17:19:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_rotates_cost(t_stack *stack, int index, char c)
{
	if (c == 'a')
	{
		if ((stack->size_a - index) < index)
			return (stack->size_a - index);
		return (index);
	}
	else if (c == 'b')
	{
		if ((stack->elements_b - index) < index)
			return (stack->elements_b - index);
		return (index);
	}
	return (-1);
}
