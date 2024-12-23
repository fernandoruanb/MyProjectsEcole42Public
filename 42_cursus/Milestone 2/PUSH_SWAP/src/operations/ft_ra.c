/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:15:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 16:40:00 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_ra(t_stack *stack, int total, int flag)
{
	int	temp;
	int	index;

	if (total < 2)
		return ;
	temp = stack->stack_a[0];
	index = 1;
	while (index < total)
	{
		stack->stack_a[index - 1] = stack->stack_a[index];
		index++;
	}
	stack->stack_a[total] = temp;
	if (flag == 1)
		ft_printf("ra\n");
}
