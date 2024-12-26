/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:39:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/26 11:47:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ra_loop(t_stack *stack, int count)
{
	while (count >= 0)
	{
		ft_ra(stack, 1);
		count--;
	}
}

static void	move_num_to_b(t_stack *stack, int local)
{
	if (local == 0)
		ft_pb(stack, 1);
	else if (local == 1)
	{
		ft_sa(stack, 1);
		ft_pb(stack, 1);
	}
	else if (local == 2)
	{
		ra_loop(stack, 1);
		ft_pb(stack, 1);
	}
	else if (local == 3)
	{
		ra_loop(stack, 2);
		ft_pb(stack, 1);
	}
	else if (local == 4)
	{
		ft_rra(stack, 1);
		ft_pb(stack, 1);
	}
}

void	five_elements(t_stack *stack)
{
	int	first;

	first = 0;
	find_smallest_num(stack, &first);
	move_num_to_b(stack, first);
	first = 0;
	find_smallest_num(stack, &first);
	move_num_to_b(stack, first);
	three_elements(stack);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
}
