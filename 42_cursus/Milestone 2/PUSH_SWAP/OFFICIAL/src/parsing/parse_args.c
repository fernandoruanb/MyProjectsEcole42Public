/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:17:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 15:01:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	has_duplicates(t_stack *stack)
{
	int	index;
	int	s_index;

	index = 0;
	while (index < stack->count - 1)
	{
		s_index = index + 1;
		while (s_index < stack->count)
		{
			if (stack->stack_a[index] == stack->stack_a[s_index])
				return (1);
			else
				s_index++;
		}
		index++;
	}
	return (0);
}

static int	append_stack(int value, t_stack *stack)
{
	if (stack->size_a < stack->count || stack->count < 0)
		return (0);
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
		while (result[index] != NULL)
		{
			free(result[index]);
			index++;
		}
		free(result);
		result = NULL;
	}
	if (stack)
	{
		free(stack->stack_a);
		free(stack->stack_b);
	}
	return (0);
}

static int	check_str(const char *s, char **res, t_stack *stack)
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
	if (has_duplicates(stack))
		return (erase_split_stack(res, stack));
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack)
{
	char	**result;
	int		index;
	int		s_index;

	index = 1;
	s_index = 0;
	if (is_nothing(argv))
		return (erase_split_stack(NULL, stack));
	while (index < argc)
	{
		result = ft_split(argv[index], ' ');
		if (!result)
			return (0);
		s_index = 0;
		while (result[s_index] != NULL)
		{
			if (!check_str(result[s_index], result, stack))
				return (0);
			s_index++;
		}
		erase_split_stack(result, NULL);
		index++;
	}
	return (1);
}
