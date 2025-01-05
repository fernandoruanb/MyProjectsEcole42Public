/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 08:46:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/26 15:41:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_smallest_num(t_stack *stack, int *index)
{
	int	target_number;
	int	flag;
	int	check;

	check = *index;
	target_number = stack->stack_a[*index];
	flag = 0;
	while (*index < stack->size_a)
	{
		if (target_number > stack->stack_a[*index])
		{
			target_number = stack->stack_a[*index];
			flag = *index;
			*index = check;
		}
		(*index)++;
	}
	*index = flag;
}
