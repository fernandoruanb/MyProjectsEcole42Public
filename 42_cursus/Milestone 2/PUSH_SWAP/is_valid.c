/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:18:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/19 16:10:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*reallocate_heap_memory(char **values, t_stacks stacks)
{
	int	index;
	int	new_values;
	int	*temp;

	index = 0;
	new_values = 0;
	while (values[new_values] != NULL)
		new_values++;
	if (stacks->stack_a)
	{
		while (stacks->stack_a[index])
			index++;
		temp = (int *)malloc(index + new_values);
		if (!temp)
			return (0);
		if ()
}

int	is_valid(char **values, t_stack *stacks)
{
	long	index;
	long	value;

	if (!stacks->position)
		stacks->position = 0;
	stacks->stack_a = reallocate_heap_memory(values, stacks);
	if (!stacks->stack_a)
		return (0);
	index = 0;
	while (values[index] != NULL)
	{
		value = ft_atoi(values[index]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		stacks->stack_a[stacks->position] = (int)value;
		stacks->position++;
		index++;
	}
	return (1);
}
