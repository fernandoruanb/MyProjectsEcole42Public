/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pre_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:53:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/04 16:47:39 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_pre_sorted(t_stack *stack)
{
	int	index;
	int	flag;

	index = 0;
	while (stack->stack_a[index] < stack->stack_a[index + 1]
		&& index < stack->size_a)
		index++;
	flag = index;
	index++;
	while (stack->stack_a[index] < stack->stack_a[index + 1]
		&& stack->stack_a[index] < stack->stack_a[0]
		&& index < stack->size_a)
		index++;
	if (index == stack->size_a - 1)
		index++;
	flag = index - flag - 1;
	if (index == stack->size_a)
	{
		while (flag-- != 0)
			ft_rra(stack, 1);
		return (1);
	}
	return (0);
}
