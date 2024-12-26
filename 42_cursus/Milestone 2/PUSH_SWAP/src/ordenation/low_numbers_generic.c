/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_numbers_generic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/26 12:07:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	low_numbers_generic(t_stack *stack)
{
	int	counter;
	int	second_counter;
	int	first;

	first = 0;
	counter = stack->size_a;
	while (counter != 6)
	{
		find_smallest_num(stack, &first);
		move_to_b(stack, &first);
		counter--;
	}
	six_elements(stack);
	second_counter = stack->elements_b;
	while (second_counter != 0)
	{
		ft_pa(stack, 1);
		second_counter--;
	}
}
