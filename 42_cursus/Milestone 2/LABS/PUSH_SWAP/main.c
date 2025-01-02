/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:44:53 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 10:21:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || argc == 2 && !argv[1][0])
		return (1);
	else if (argv == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!check_sorted(a))
	{
		if (stack_len(a) == 2)
			ft_sa(&a);
		else if (stack_len(b) == 3)
			three_elements_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stacks(&a);
	return (0);
}
