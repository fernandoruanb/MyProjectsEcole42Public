/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:20:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 10:33:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack *stack, int total)
{
	if (!stack)
		return (ft_putendl_fd_0("stack doesn't exist", 2));
	stack->stack_a = (int *)malloc(total * sizeof(int));
	if (!stack->stack_a)
		return (ft_putendl_fd_0("Failed malloc int stack_a", 2));
	stack->size_a = total;
	stack->stack_b = (int *)malloc(1 * sizeof(int));
	if (!stack->stack_b)
		return (ft_putendl_fd_0("Failed malloc int stack_b", 2));
	stack->size_b = 1;
	stack->elements_b = 0;
	stack->operations = 0;
	stack->count = 0;
	return (1);
}