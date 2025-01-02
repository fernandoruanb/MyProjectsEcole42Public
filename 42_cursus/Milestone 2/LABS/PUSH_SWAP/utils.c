/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:16:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 13:03:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	length;

	if (!stack)
		return (0);
	length = 0;
	while (stack)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

t_stack	*find_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	check_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min_node;
	long	min;

	if (!stack)
		return (NULL);
	min_node = NULL;
	min = LONG_MAX;
	while (stack)
	{
		if (stack->num < min)
		{
			min = stack->num;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*find_max_node(t_stack *stack)
{
	int		max;
	t_stack	max_node;

	if (!stack)
		return (NULL);
	max_node = NULL;
	max = LONG_MIN;
	while (stack)
	{
		if (stack->num > max)
		{
			max = stack->num;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
