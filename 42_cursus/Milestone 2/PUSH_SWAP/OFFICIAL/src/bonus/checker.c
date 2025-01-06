/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:42:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/06 12:42:49 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	execute_commands(t_stack *stack, const char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		ft_pa(stack, 1);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_pb(stack, 1);
	else if (ft_strcmp(str, "sa\n") == 0)
		ft_sa(stack, 1);
	else if (ft_strcmp(str, "sb\n") == 0)
		ft_sb(stack, 1);
	else if (ft_strcmp(str, "pa\n") == 0)
		ft_pa(stack, 1);
	else if (ft_strcmp(str, "ss\n") == 0)
		ft_ss(stack);
	else if (ft_strcmp(str, "ra\n") == 0)
		ft_ra(stack, 1);
	else if (ft_strcmp(str, "rb\n") == 0)
		ft_rb(stack, 1);
	else if (ft_strcmp(str, "rr\n") == 0)
		ft_rr(stack);
	else if (ft_strcmp(str, "rrr\n") == 0)
		ft_rrr(stack);
	else if (ft_strcmp(str, "rra\n") == 0)
		ft_rra(stack, 1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		ft_rrb(stack, 1);
}

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

static void	get_args_and_do(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (1)
	{
		if (line == NULL)
			break ;
		execute_commands(stack, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	int		total_numbers;
	t_stack	stack;

	if (argc < 2)
		return (1);
	total_numbers = count_all_numbers(argc, argv);
	if (!init_stack(&stack, total_numbers))
		return (1);
	if (!parse_args(argc, argv, &stack))
		return (1);
	get_args_and_do(&stack);
	divine_checker(&stack);
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
