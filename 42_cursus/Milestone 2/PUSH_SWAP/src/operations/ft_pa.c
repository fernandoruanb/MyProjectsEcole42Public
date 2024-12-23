/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:43:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 19:22:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pa(t_stack *stack, int flag)
{
	int	temp;

	if (total_numbers == 0 || stack->position_b == total_numbers)
		return ;
	temp = stack->stack_a[0];
	stack->count = size_a;
	while (stack->count > 0)
	{
		stack->stack_a[count - 1] = stack->stack_a[count];
		count--;
	}
	if (flag == 1)
		ft_printf("pa\n");
}
