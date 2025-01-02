/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:08:36 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 13:27:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*a_node_check;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		a_node_check = a;
		while (a_node_check)
		{
			if (a_node_check->num > b->num
				&& a_node_check->num < best_match_index)
			{
				best_match_index = a_node_check->num;
				target_node = a_node_check;
			}
			a_node_check = a_node_check->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	stack_indexation(a);
	stack_indexation(b);
	set_target_b(a, b);
}
