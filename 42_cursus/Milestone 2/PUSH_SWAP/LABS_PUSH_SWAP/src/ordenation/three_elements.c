/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:23:37 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 10:01:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	three_elements(t_stack *stack)
{
	int	last;

	last = stack->size_a - 1;
	if (stack->stack_a[0] > stack->stack_a[1])
		ft_sa(stack, 1);
	if ((stack->stack_a[0] > stack->stack_a[last])
		|| (stack->stack_a[1] > stack->stack_a[0]
			&& stack->stack_a[1] > stack->stack_a[2]))
		ft_rra(stack, 1);
	if (stack->stack_a[0] > stack->stack_a[1])
		ft_sa(stack, 1);
}
