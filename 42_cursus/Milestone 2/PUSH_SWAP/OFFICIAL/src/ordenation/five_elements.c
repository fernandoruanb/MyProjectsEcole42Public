/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:39:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/26 14:45:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	five_elements(t_stack *stack)
{
	int	first;

	first = 0;
	find_smallest_num(stack, &first);
	move_to_b(stack, &first);
	first = 0;
	find_smallest_num(stack, &first);
	move_to_b(stack, &first);
	three_elements(stack);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
}
