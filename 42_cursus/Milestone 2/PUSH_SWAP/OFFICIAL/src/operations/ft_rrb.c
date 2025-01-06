/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:29:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 10:43:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rrb(t_stack *stack, int flag)
{
	int		temp;
	int		index;
	int		*new_arr;

	if (stack->elements_b <= 2)
		return ;
	temp = stack->stack_b[stack->elements_b - 1];
	new_arr = (int *)ft_calloc(stack->elements_b, sizeof(int));
	if (!new_arr)
		return ;
	index = 1;
	while (index < stack->elements_b)
	{
		new_arr[index] = stack->stack_b[index - 1];
		index++;
	}
	new_arr[0] = temp;
	free(stack->stack_b);
	stack->stack_b = new_arr;
	if (flag == 1)
	{
		ft_printf("rrb\n");
		stack->operations++;
	}
}
