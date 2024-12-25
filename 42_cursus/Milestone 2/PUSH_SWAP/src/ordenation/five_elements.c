/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:39:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 18:51:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*static void	move_n1(t_stack *stack)
{
}*/

void	five_elements(t_stack *stack)
{
	int	first;
	int	second;

	first = 0;
	second = 0;
	find_smallest_n1(stack, &first);
	find_smallest_n2(stack, &second, first);
	//move_n1(stack);
	ft_printf("%d, %d\n", first, second);
}
