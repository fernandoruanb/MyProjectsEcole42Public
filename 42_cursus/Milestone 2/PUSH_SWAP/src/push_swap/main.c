/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:08:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/24 08:59:26 by fruan-ba         ###   ########.fr       */
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
	index = 0;
	while (index < total_numbers)
		ft_printf("%d ", stack.stack_a[index++]);
	ft_printf("\n");
	if (is_sorted(&stack, total_numbers))
		return (ft_putendl_fd_0("Is sorted!", 2));
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
