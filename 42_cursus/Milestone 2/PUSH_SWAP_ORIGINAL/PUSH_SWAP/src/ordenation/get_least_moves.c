/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_least_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:16:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/26 15:17:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_least_moves(t_stack *stack, int *local)
{
	if (stack->size_a - *local < *local)
		return (1);
	return (0);
}
