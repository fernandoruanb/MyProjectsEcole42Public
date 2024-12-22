/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:17:06 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/22 13:51:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_regular_str(const char *s, char **res, t_stack *stack_a)
{
	int	value;
	int	error;

	error = 0;
	init_stack_a(stack_a);
	if (!is_number(s))
		return (erase_split_stack(res, stack_a));
	value = ft_atoi_check(s, &error);
	if (error == 1)
		return (erase_split_stack(res, stack_a));
	if (!append_stack_a(value, stack_a))
		return (erase_split_stack(res, stack_a));
	stack_a->size_a++;
	if (has_duplicates(stack_a))
		return (erase_split_stack(res, stack_a));
	return (1);
}

int	parse_args(int argc, char **argv)
{
	char	**result;
	int		index;
	int		s_index;
	t_stack	stack_a;

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
			if (!check_regular_str(result[s_index], result, &stack_a))
				return (ft_putendl_fd_0("Invalid things found", 2));
			s_index++;
		}
		index++;
	}
	erase_split_stack(res, NULL);
	return (1);
}
