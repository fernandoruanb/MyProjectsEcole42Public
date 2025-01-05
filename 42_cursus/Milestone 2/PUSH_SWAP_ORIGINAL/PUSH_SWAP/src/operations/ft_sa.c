/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:10:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 10:34:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_stack *stack, int flag)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = temp;
	if (flag == 1)
	{
		ft_printf("sa\n");
		stack->operations++;
	}
}
