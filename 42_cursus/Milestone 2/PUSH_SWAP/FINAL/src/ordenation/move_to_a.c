/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:57:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/26 18:19:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	organize_a_by_index(t_stack *stack, int *local)
{
	int			moves;
	int			target;
	static int	position;

	position = 0;
	target = stack->stack_a[*local];
	moves = get_least_moves(stack, local);
	if (moves)
	{
		while (stack->stack_a[position] != target)
			ft_rra(stack, 1);
		position++;
	}
	else
	{
		while (stack->stack_a[position] != target)
			ft_ra(stack, 1);
		position++;
	}
}
