/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:45:40 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/12 09:25:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int	*numbers_a;
	int	*numbers_b;
	int	size_a;
	int	size_b;
	int	capacity_a;
	int	capacity_b;
}		t_stacks;

int	parse_args(int argc, char **argv, t_stacks *stack);

#endif /* PUSH_SWAP_H */
