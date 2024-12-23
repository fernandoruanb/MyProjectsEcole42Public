/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:58:00 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 18:28:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rrb(t_stack *stack, int flag)
{
	int	index;
	int	validate;
	int	temp;

	validate = position_b + 1;
	if (validate >= t_stack->size_b)
		return ;
	index = 0;
	temp = stack->stack_b[0];
	while (index < t_stack->size_b)
	{
		stack->stack_a[index + 1] = stack->stack_a[index];
		index++;
	}
	stack->stack_b[0] = temp;
	if (flag == 1)
		ft_printf("rrb\n");
}
