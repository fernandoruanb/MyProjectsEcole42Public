/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:33:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/20 16:16:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stack_a;

	if (argc < 2)
	{
		printf("How to use: ./push_swap [arg1] [args...]\n");
		return (1);
	}
	if (!parse_args(argc, argv))
		return (ft_putstr_fd_1("Invalid arguments.\n", 2));
	if (!initialize_stack_a(argc, argv, stack_a))
		return (ft_putstr_fd_1("Cannot initialize stack_a\n", 2));
	return (0);
}
