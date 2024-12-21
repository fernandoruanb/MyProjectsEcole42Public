/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:12:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/20 17:15:40 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicates(t_stacks stack)
{
	int	index;

	index = 1;
	while (stack->stack_a[index])
	{
		s_index = index - 1;
		if (stack->stack_a[index] == stack->stack_a[s_index])
			return (ft_putstr_fd_1(""));
	}
	index = 0;
}

static int	parsing_numbers_to_stack(char **result, t_stacks stack)
{
	int	index;
	long	value;

	index = 0;
	while (result[index] != NULL)
	{
		value = ft_atoi(result[index]);
		stack.stack_a[index] = (int)value;
		free(result[index]);
		index++;
	}
	free(result);
	if (has_duplicates(t_stacks stack))
		return (ft_putstr_fd_0("There is/are duplicates.\n", 2));
	return (1);
}

int	initialize_stack_a(int argc, char **argv, t_stacks stack)
{
	int	size;
	char	**result;

	if (argc < 2)
		return (1);
	while (argv[size])
		size++;
	stack->stack_a = (int *)malloc(size * 4);
	if (!stack->stack_a)
		return (ft_putstr_fd_0("Error allocating stack_a.\n", 2));
	result = ft_split(argv[1]);
	if (!result)
		return (0);
	if (!parsing_numbers_to_stack(result, stack))
		return (ft_putstr_fd_0("Error parsing number stack_a.\n", 2));
	return (1);
}	
