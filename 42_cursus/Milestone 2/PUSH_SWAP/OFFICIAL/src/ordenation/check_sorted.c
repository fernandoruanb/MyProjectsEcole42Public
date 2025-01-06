/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:10:42 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/26 18:17:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_sorted(t_stack *stack)
{
	int	index;
	int	s_index;

	index = 0;
	while (index < stack->size_a)
	{
		s_index = index + 1;
		while (s_index < stack->size_a)
		{
			if (stack->stack_a[index] > stack->stack_a[s_index])
				return (0);
			s_index++;
		}
		index++;
	}
	return (1);
}
