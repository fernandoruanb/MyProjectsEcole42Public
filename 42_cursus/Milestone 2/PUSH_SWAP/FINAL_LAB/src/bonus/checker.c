/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:42:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/05 18:00:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	divine_checker(t_stack *stack)
{
	int	index;
	int	s_index;

	index = 0;
	while (index < stack->size_a)
	{
		s_index = index + 1;
		while (s_index < stack->size_a)
		{
			if (stack->stack_a[index] > stack->stack_a[s_index])
			{
				ft_printf("KO\n");
				return ;
			}
			s_index++;
		}
		index++;
	}
	ft_printf("OK\n");
}

int	main(int argc, char **argv)
{
	int		total_numbers;
	t_stack	stack;

	if (argc < 2)
		return (1);
	total_numbers = count_all_numbers(argc, argv);
	if (!init_stack(&stack, total_numbers))
		return (ft_putendl_fd_1("Error", 2));
	if (!parse_args(argc, argv, &stack))
		return (ft_putendl_fd_1("Error", 2));
	if (is_sorted(&stack, stack.size_a, 0))
	{
		divine_checker(&stack);
		free(stack.stack_a);
		free(stack.stack_b);
		return (0);
	}
	divine_checker(&stack);
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
