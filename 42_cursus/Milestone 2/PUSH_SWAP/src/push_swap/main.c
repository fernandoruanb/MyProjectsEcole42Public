/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:08:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 11:57:54 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	int		index;
	int		total_numbers;
	t_stack	stack;

	if (argc < 2)
		return (ft_putendl_fd_1("Too few arguments.", 2));
	total_numbers = count_all_numbers(argc, argv);
	if (!init_stack(&stack, total_numbers))
		return (ft_putendl_fd_1("Failed init stacks", 2));
	if (!parse_args(argc, argv, &stack))
		return (1);
	//ft_pb(&stack, 1);
	//ft_pb(&stack, 1);
	//ft_pb(&stack, 1);
	//ft_pa(&stack, 1);
	//ft_pa(&stack, 1);
	//ft_ra(&stack, 1);
	//ft_rb(&stack, 1);
	//ft_rr(&stack);
	//ft_rra(&stack, 1);
	//ft_rrb(&stack, 1);
	//ft_rrr(&stack);
	index = 0;
	while (index < stack.size_a)
		ft_printf("%d ", stack.stack_a[index++]);
	ft_printf("\n");
	index = 0;
	while (index < stack.elements_b)
		ft_printf("%d ", stack.stack_b[index++]);
	if (is_sorted(&stack, stack.size_a, 0))
		return (ft_putendl_fd_0("Is sorted!", 2));
	index = 0;
	while (index < stack.size_a)
		ft_printf("%d ", stack.stack_a[index++]);
	ft_printf("\n");
	ft_printf("Operations: %d\n", stack.operations);
	if (is_sorted(&stack, stack.size_a, 1))
		ft_putendl_fd_0("Is sorted!", 2);
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
