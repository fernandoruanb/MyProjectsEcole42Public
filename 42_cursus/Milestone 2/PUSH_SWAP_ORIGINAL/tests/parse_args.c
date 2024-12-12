/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:04:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/12 10:13:15 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parsing_elements_to_stack_a(int argc, char **argv, t_struct *stack)
{
	int	*numbers;

	numbers = (int *)malloc(stack->size_a, sizeof(size_a));
	if (!numbers)
	return (1);
}

static int	has_duplicate(char *number)
{

	return (0);
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	parse_args(int argc, char **argv, t_struct *stack)
{
	unsigned int	index;
	unsigned int	s_index;

	stack->size = 0;
	index = 1;
	while (index < argc)
	{
		s_index = 0;
		while (argv[index][s_index] != '\0')
		{
			while ((argv[index][s_index]) && (argv[index][s_index] == ' '
				|| argv[index][s_index] == '\t'))
				s_index++;
			if (!ft_isdigit(argv[index][s_index]))
				return (0);
			if (has_duplicate(argv[index])
				return (0);
			s_index++;
			stack->size++;
		}
		index++;
	}
	if (!parsing_elements_to_stack_a(argc, argv, stack))
		return (ft_putstr_fd_0("Error initializing stack_a", 2));
	return (1);
}
