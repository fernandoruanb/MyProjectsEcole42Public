/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:21:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 19:11:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sb(t_stack *stack, int flag)
{
	int	temp;

	if (stack->elements_b < 2)
		return ;
	temp = stack->stack_b[stack->size_b - 1];
	stack->stack_b[stack->size_b - 1] = stack->stack_b[stack->size_b - 2];
	stack->stack_b[stack->size_b - 2] = temp;
	if (flag == 1)
		ft_printf("sb\n");
}
