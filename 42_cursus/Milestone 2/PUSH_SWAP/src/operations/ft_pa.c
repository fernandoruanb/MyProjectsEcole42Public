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

	if (stack->elements_b == 0)
		return ;
	temp = stack->stack_b[stack->size_b - stack->elements_b];
	stack->stack_a[stack->size_a - stack->elements_a - 1] = temp;
	stack->elements_a++;
	stack->elements_b--;	
	if (flag == 1)
		ft_printf("pa\n");
}
