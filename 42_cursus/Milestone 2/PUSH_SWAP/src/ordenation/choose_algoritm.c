/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algoritm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 08:49:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/30 18:09:41 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	choose_algoritm(t_stack *stack, int flag)
{
	if (flag == 1)
		return (ft_putendl_fd_0("Isn't sorted!", 2));
	if (stack->size_a == 2)
		two_elements(stack);
	else if (stack->size_a == 3)
		three_elements(stack);
	/*else if (stack->size_a == 4)
		four_elements(stack);
	else if (stack->size_a == 5)
		five_elements(stack);
	else if (stack->size_a == 6)
		six_elements(stack);
	else if (stack->size_a <= 15)
		low_numbers_generic(stack);*/
	else
		high_numbers_generic(stack);
	return (0);
}
