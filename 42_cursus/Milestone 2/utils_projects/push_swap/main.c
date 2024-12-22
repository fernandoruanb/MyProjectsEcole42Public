/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:08:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/22 10:15:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		total_numbers;

	if (argc < 2)
		return (ft_putendl_fd_1("Too few arguments.", 2));
	total_numbers = count_all_numbers(argc, argv);
	stack_a = initialize_stack_a(&stack_a, total_numbers);
	if (!stack_a)
		return (1);
	stack_b = initialize_stack_b(&stack_b, total_numbers);
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	fill_stack_a(argc, argv, &stack_a);
	return (0);
}
