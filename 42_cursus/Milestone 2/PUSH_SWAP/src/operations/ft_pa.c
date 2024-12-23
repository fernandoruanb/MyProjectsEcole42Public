/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:43:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/23 15:58:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_pa(t_stack *stack, int total_numbers, int flag)
{
	int	space_b;
	int	space_a;

	if (total_numbers == 0 || stack->position_b == total_numbers)
		return ;
	space_a = stack->top_a - 1;
	space_b = stack->position_b + 1;
	stack->stack_b[space] = stack->stack_a[space_a];
	if (flag == 1)
		ft_printf("pa");
}
