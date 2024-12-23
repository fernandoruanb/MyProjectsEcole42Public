/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:43:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 14:05:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pa(t_stack *stack, int total_numbers)
{
	if (total_numbers == 0)
		return ;
	stack->stack_b[elements_b] = stack->stack_a[0];
	stack->elements_b++;
}
