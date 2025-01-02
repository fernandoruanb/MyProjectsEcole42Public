/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_to_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:59:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 12:04:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_to_push(t_stack **stack, t_stack *top_node
		char	stack_name)
{
	if (stack_name == 'a')
	{
		while (*stack != top_node)
		{
			if (top_node->above_diviser_line)
				ft_ra(stack, false);
			else
				ft_rra(stack, false);
		}
	}
	else if (stack_name == 'b')
	{
		while (*stack != top_node)
		{
			if (top_node->above_diviser_line)
				ft_rb(stack, false);
			else
				ft_rrb(stack, false);
		}
	}
}
