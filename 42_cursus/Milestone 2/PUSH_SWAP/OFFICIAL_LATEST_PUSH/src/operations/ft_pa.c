/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:14:46 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/25 10:37:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	mark_all_notices(t_stack *stack, int flag)
{
	if (flag == 1)
	{
		ft_printf("pa\n");
		stack->operations++;
	}
}

static int	move_all_elements_pa(t_stack *stack)
{
	int	index;
	int	*new_arr;

	new_arr = (int *)ft_calloc(stack->size_b - 1, sizeof(int));
	if (!new_arr)
		return (ft_putendl_fd_0("Failed allocating new_arr pa", 2));
	else
	{
		index = 1;
		while (index < stack->elements_b)
		{
			new_arr[index - 1] = stack->stack_b[index];
			index++;
		}
		free(stack->stack_b);
		stack->stack_b = new_arr;
	}
	stack->elements_b--;
	return (1);
}

void	ft_pa(t_stack *stack, int flag)
{
	int	temp;
	int	*new_arr;
	int	index;

	if (stack->elements_b <= 0)
		return ;
	new_arr = (int *)ft_calloc(stack->size_a + 1, sizeof(int));
	if (!new_arr)
		return ;
	temp = stack->stack_b[0];
	index = 0;
	while (index < stack->size_a)
	{
		new_arr[index + 1] = stack->stack_a[index];
		index++;
	}
	stack->size_a++;
	free(stack->stack_a);
	stack->stack_a = new_arr;
	stack->stack_a[0] = temp;
	if (!move_all_elements_pa(stack))
		return ;
	mark_all_notices(stack, flag);
}
