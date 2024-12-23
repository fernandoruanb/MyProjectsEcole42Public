/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:24:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 19:26:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pb(t_stack *stack, int flag)
{
	int	count;

	stack->stack_b[stack->position_b] = stack->stack_a[stack->top_a];
	stack->top_a++;
	stack->position_b--;
	count = stack->size_b;
	while (stack_b->position_b < count)
	{
		
	}
	if (flag == 1)
		ft_printf("pb\n");
}
