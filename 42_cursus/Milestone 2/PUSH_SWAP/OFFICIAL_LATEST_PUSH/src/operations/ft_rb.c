/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:15:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 10:42:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rb(t_stack *stack, int flag)
{
	int	index;
	int	*new_str;
	int	temp;

	if (stack->elements_b < 2)
		return ;
	new_str = (int *)ft_calloc(stack->elements_b, sizeof(int));
	if (!new_str)
		return ;
	index = 0;
	temp = stack->stack_b[0];
	while (index < stack->elements_b - 1)
	{
		new_str[index] = stack->stack_b[index + 1];
		index++;
	}
	new_str[stack->elements_b - 1] = temp;
	free(stack->stack_b);
	stack->stack_b = new_str;
	if (flag == 1)
	{
		ft_printf("rb\n");
		stack->operations++;
	}
}
