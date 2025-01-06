/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_best_movement_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:32:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/31 20:05:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	choose_best_movement_a(t_stack *stack, int target, int moves)
{
	if (moves == 1)
	{
		while (stack->stack_a[0] != target)
			ft_rra(stack, 1);
		ft_pa(stack, 1);
	}
	else if (moves == 0)
	{
		while (stack->stack_a[0] != target)
			ft_ra(stack, 1);
		ft_pa(stack, 1);
	}
}
