/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:36:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 15:39:52 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*stack_now;

	if (!stack)
		return ;
	stack_now = *stack;
	while (stack_now)
	{
		tmp = stack_now->next;
		free(stack_now);
		stack_now = tmp;
	}
	*stack = NULL;
}
