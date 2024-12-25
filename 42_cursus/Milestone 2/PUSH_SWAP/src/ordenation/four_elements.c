/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 10:49:52 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 12:13:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	four_elements(t_stack *stack)
{
	ft_pb(stack, 1);
	three_elements(stack);
	ft_pb(stack, 1);
	if (stack->stack_b[0] < stack->stack_b[1])
		ft_sb(stack, 1);
	ft_pa(stack, 1);
	three_elements(stack);
	ft_pa(stack, 1);
}
