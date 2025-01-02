/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:31:52 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 11:42:29 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack **a, int num)
{
	t_stack	new_node;
	t_stack	*last_node;

	if (!a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	new_node->next = NULL;
	new_node->is_cheapest = 0;
	new_node->num = num;
	if (!(*a))
	{
		new_node->prev = NULL;
		*a = new_node;
	}
	else
	{
		last_node = find_last_node(*a);
		new_node->prev = last_node;
		last_node->next = new_node;
		*a = new_node;
	}
}

void	init_stack_a(t_stack **a, char **argv)
{
	long	num;
	int		index;

	index = 1;
	while (argv[index])
	{
		if (!valid_arg(argv[index]))
			clean_program(a);
		num = ft_atol(argv[index]);
		if (num < INT_MIN || num > INT_MAX)
			clean_program(a);
		if (has_duplicates(*a, (int)num))
			clean_program(a);
		append_node(a, (int)num);
		index++;
	}
}
