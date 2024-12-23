/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:24:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 15:51:45 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pb(t_stack *stack, int flag)
{
	stack->stack_b[stack->position_b] = stack->stack_a[stack->top_a];
	stack->top_a++;
	stack->position_b--;
	if (flag == 1)
		ft_printf("pb\n");
}
