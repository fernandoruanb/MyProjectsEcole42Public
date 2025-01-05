/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:48:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 10:43:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rra(t_stack *stack, int flag)
{
	int	*new_arr;
	int	temp;
	int	index;

	if (stack->size_a < 2)
		return ;
	new_arr = (int *)ft_calloc(stack->size_a, sizeof(int));
	if (!new_arr)
		return ;
	temp = stack->stack_a[stack->size_a - 1];
	index = 1;
	while (index < stack->size_a)
	{
		new_arr[index] = stack->stack_a[index - 1];
		index++;
	}
	new_arr[0] = temp;
	free(stack->stack_a);
	stack->stack_a = new_arr;
	if (flag == 1)
	{
		ft_printf("rra\n");
		stack->operations++;
	}
}
