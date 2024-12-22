/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 10:19:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/22 10:57:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	fill_stack_a(int argc, char **argv, t_stack *stack_a)
{
	int		index;
	int		s_index;
	char	**result;

	index = 1;
	s_index = 0;
	while (index < argc)
	{
		result = ft_split(argv[index], ' ');
		if (!result)
			return (ft_putendl_fd_0("Failed filling s_a", 2));
		while (result[stack->size_a] != NULL)
		{
			s_index = 0;
			stack_a->stack_a[stack_a->size_a++]
				= ft_atoi_checker(result[s_index++], &error);
		}
		if (error == 1)
		{
			free(stack_a->stack_a);
			return (0);
		}
		free(result);
	}
	return (1);
}
