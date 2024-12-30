/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_location_max_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:21:17 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/29 10:17:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_location_max_b(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack->stack_b[index] != stack->max_b)
		index++;
	return (index);
}
