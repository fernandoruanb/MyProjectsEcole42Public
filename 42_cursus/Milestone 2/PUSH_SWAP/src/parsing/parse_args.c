/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:17:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/22 16:10:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	append_stack(int value, t_stack *stack)
{
	if (stack->size_a < stack->count || stack->count < 0)
		return (ft_putendl_fd_0("Over/Underflow attempt detected", 2));
	else
		stack->stack_a[stack->count] = value;
	return (1);
}

static int	erase_split_stack(char **result, t_stack *stack)
{
	int	index;

	if (result)
	{
		index = 0;
		while (result[index++] != NULL)
			free(result[index]);
		free(result);
	}
	if (stack)
	{
		free(stack->stack_a);
		free(stack->stack_b);
		free(stack);
	}
	return (0);
}

static int	check_regular_str(const char *s, char **res, t_stack *stack)
{
	int	value;
	int	error;

	error = 0;
	if (!is_number(s))
		return (erase_split_stack(res, stack));
	value = ft_atoi_check(s, &error);
	if (error == 1)
		return (erase_split_stack(res, stack));
	if (!append_stack(value, stack))
		return (erase_split_stack(res, stack));
	stack->count++;
	//if (has_duplicates(stack))
	//	return (erase_split_stack(res, stack));
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack)
{
	char	**result;
	int		index;
	int		s_index;

	index = 1;
	s_index = 0;
	while (index < argc)
	{
		result = ft_split(argv[index], ' ');
		if (!result)
			return (ft_putendl_fd_0("Error allocating split", 2));
		s_index = 0;
		while (result[s_index] != NULL)
		{
			if (!check_regular_str(result[s_index], result, stack))
				return (ft_putendl_fd_0("Invalid things found", 2));
			s_index++;
		}
		index++;
	}
	erase_split_stack(result, NULL);
	return (1);
}
