/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 09:40:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 09:46:01 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	show_stacks(t_stack *stack, char flag)
{
	int	index;

	if (flag == 'a')
	{
		index = 0;
		while (index < stack->size_a)
			ft_printf("%d ", stack->stack_a[index++]);
		ft_printf("\n");
	}
	else if (flag == 'b')
	{
		index = 0;
		while (index < stack->elements_b)
			ft_printf("%d ", stack->stack_b[index++]);
		ft_printf("\n");
	}
	return ;
}
