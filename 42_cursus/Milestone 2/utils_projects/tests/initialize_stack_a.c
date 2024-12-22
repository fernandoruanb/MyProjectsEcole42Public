/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:27:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/21 19:27:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_stack_a(int total_numbers)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (ft_putendl_fd_n("Error allocating stack_a", 2));
	stack->stack_a = (int *)malloc(sizeof(int) * total_numbers);
	if (!stack->stack_a)
	{
		free(stack);
		return (ft_putendl_fd_n("Stack_a failed!", 2));
	}
	stack->size_a = total_numbers;
	return (stack);
}
