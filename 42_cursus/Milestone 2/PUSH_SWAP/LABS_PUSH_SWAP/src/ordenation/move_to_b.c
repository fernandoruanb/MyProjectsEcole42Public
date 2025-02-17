/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:53:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/26 18:43:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	move_to_b(t_stack *stack, int *local)
{
	int	moves;
	int	target;

	target = stack->stack_a[*local];
	moves = get_least_moves(stack, local);
	if (moves)
	{
		while (stack->stack_a[0] != target)
			ft_rra(stack, 1);
	}
	else if (moves == 0)
	{
		while (stack->stack_a[0] != target)
			ft_ra(stack, 1);
	}
	if (check_sorted(stack))
		return (1);
	ft_pb(stack, 1);
	return (0);
}
