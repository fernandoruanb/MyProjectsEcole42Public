/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:56:23 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 10:42:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_ra(t_stack *stack, int flag)
{
	int	index;
	int	*new_str;
	int	temp;

	if (stack->size_a < 2)
		return ;
	new_str = (int *)ft_calloc(stack->size_a, sizeof(int));
	if (!new_str)
		return ;
	temp = stack->stack_a[0];
	index = 0;
	while (index < stack->size_a - 1)
	{
		new_str[index] = stack->stack_a[index + 1];
		index++;
	}
	new_str[stack->size_a - 1] = temp;
	free(stack->stack_a);
	stack->stack_a = new_str;
	if (flag == 1)
	{
		ft_printf("ra\n");
		stack->operations++;
	}
}
