/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:10:28 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 17:44:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_rra(t_stack *stack, int total, int flag)
{
	int	index;
	int	temp;

	if (total < 2)
		return ;
	index = 0;
	temp = stack->stack_a(stack->stack_a[size_a]);
	while (index < total)
	{
		stack->stack_a[index + 1] = stack->stack_a[index];
		index++;
	}
	stack->stack_a[0] = temp;
	if (flag == 1)
		ft_printf("rra\n");
}
