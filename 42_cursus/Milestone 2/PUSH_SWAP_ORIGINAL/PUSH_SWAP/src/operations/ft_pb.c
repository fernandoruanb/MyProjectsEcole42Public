/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:14:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 18:36:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	mark_all_news(t_stack *stack, int flag)
{
	if (flag == 1)
	{
		ft_printf("pb\n");
		stack->operations++;
	}
}

static int	move_all_elements(t_stack *stack, int temp)
{
	int	index;
	int	*new_arr;

	if (stack->elements_b == 0)
	{
		stack->stack_b[0] = temp;
		return (1);
	}
	new_arr = (int *)ft_calloc(stack->size_b + 1, sizeof(int));
	if (!new_arr)
		return (ft_putendl_fd_0("Failed allocating new_arr pb", 2));
	stack->size_b++;
	index = 1;
	while (index < stack->size_b)
	{
		new_arr[index] = stack->stack_b[index - 1];
		index++;
	}
	new_arr[0] = temp;
	free(stack->stack_b);
	stack->stack_b = new_arr;
	return (1);
}

void	ft_pb(t_stack *stack, int flag)
{
	int	temp;
	int	*new_arr;
	int	index;

	if (stack->size_a <= 1)
		return ;
	new_arr = (int *)ft_calloc(stack->size_a - 1, sizeof(int));
	if (!new_arr)
		return ;
	temp = stack->stack_a[0];
	index = 1;
	while (index < stack->size_a)
	{
		new_arr[index - 1] = stack->stack_a[index];
		index++;
	}
	stack->size_a--;
	free(stack->stack_a);
	stack->stack_a = new_arr;
	if (!move_all_elements(stack, temp))
		return ;
	stack->elements_b++;
	mark_all_news(stack, flag);
}
