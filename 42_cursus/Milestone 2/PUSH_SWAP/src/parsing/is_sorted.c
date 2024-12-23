/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:15:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 12:49:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *stack, int total)
{
	int	index;
	int	s_index;

	index = 0;
	while (index < total)
	{
		s_index = index + 1;
		while (s_index < total)
		{
			if (stack->stack_a[index] > stack->stack_a[s_index])
				return (ft_putendl_fd_0("Isn't sorted", 2));
			s_index++;
		}
		index++;
	}
	free(stack->stack_a);
	free(stack->stack_b);
	return (1);
}
