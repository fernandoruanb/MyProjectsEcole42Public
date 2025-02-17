/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:08:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/02/17 11:28:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		total_numbers;
	int		index;
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
		free(stack.stack_a);
		free(stack.stack_b);
		return (0);
	}
	index = 0;
	while (index < total_numbers)
		ft_printf("%d ", stack.stack_a[index++]);
	ft_printf("\n");
	ft_printf("Operations: %d\n", stack.operations);
	if (is_sorted(&stack, stack.size_a, 1))
		ft_printf("Is sorted! =D\n");
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
