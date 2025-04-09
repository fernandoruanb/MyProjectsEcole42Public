/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:08:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/09 10:31:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		total_numbers;
	t_stack	stack;

	if (argc < 2)
		return (1);
	total_numbers = count_all_numbers(argc, argv);
	if (total_numbers <= 0)
		return (ft_putendl_fd_1("Error", 2));
	if (!init_stack(&stack, total_numbers))
		return (ft_putendl_fd_1("Error", 2));
	if (!parse_args(argc, argv, &stack))
		return (ft_putendl_fd_1("Error", 2));
	if (is_sorted(&stack, stack.size_a, 0))
	{
		free(stack.stack_a);
		free(stack.stack_b);
		return (0);
	}
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
