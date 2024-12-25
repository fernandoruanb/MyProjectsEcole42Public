/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:39:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 13:07:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	five_elements(t_stack *stack)
{
	ft_pb(stack, 1);
	ft_pb(stack, 1);
	three_elements(stack);
	ft_pa(stack, 1);
	ft_ra(stack, 1);
	ft_pa(stack, 1);
	ft_ra(stack, 1);
}
