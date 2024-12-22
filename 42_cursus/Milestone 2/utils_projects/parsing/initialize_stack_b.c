/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stacks_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:27:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/22 10:02:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*initialize_stack_b(int total_numbers)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (ft_putendl_fd_n("Error allocating stack_a", 2));
	stack->stack_b = (int *)malloc(sizeof(int) * total_numbers);
	if (!stack->stack_b)
	{
		free(stack);
		return (ft_putendl_fd_n("Stack_a failed!", 2));
	}
	stack->size_b = total_numbers;
	return (stack);
}
