/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_best_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:32:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/29 08:40:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	choose_best_movement(t_stack *stack, int index, int moves)
{
	int	target;

	target = stack->stack_b[index];
	if (moves)
	{
		while (stack->stack_b[0] != target)
			ft_rb(stack, 1);
		ft_pb(stack, 1);
	}
	else if (moves == 1)
	{
		while (stack->stack_b[1] != target)
			ft_rrb(stack, 1);
		ft_pb(stack, 1);
	}
}
