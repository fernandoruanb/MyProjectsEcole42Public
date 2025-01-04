/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:44:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/26 11:48:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	move_smallest_num_a_b(t_stack *stack, int *local)
{
	while (*local > 0)
	{
		ft_ra(stack, 1);
		(*local)--;
	}
	ft_pb(stack, 1);
}

void	six_elements(t_stack *stack)
{
	int	location;

	location = 0;
	find_smallest_num(stack, &location);
	move_smallest_num_a_b(stack, &location);
	five_elements(stack);
	ft_pa(stack, 1);
}
