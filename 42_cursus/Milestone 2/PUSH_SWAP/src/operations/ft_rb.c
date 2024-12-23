/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:05:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 16:43:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rb(t_stack *stack, int flag)
{
	int	validate;
	int	temp;
	int	index;

	validate = stack->size_b - 2;
	if (stack->position_b - 1 > validate)
		return ;
	index = 1;
	temp = stack->stack_b[position_b - 1];
	while (index < stack->size_b)
	{
		stack->stack_b[index - 1] = stack->stack_b[index];
		index++;
	}
	stack->stack_b[size_b] = temp;
	if (flag == 1)
		ft_printf("rb\n");
}
