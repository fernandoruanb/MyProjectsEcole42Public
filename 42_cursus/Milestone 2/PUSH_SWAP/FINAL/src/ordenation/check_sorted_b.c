/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:10:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/29 09:36:21 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_sorted_b(t_stack *stack)
{
	int	index;
	int	s_index;

	index = 0;
	while (index < stack->elements_b)
	{
		s_index = index + 1;
		while (s_index < stack->elements_b)
		{
			if (stack->stack_b[index] < stack->stack_b[s_index])
				return (0);
			s_index++;
		}
		index++;
	}
	return (1);
}
