/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:14:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/02 15:14:37 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				num;
	int				push_cost;
	int				correct_position;
	bool			above_diviser_line;
	bool			is_cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next_node;
	struct s_stack	*prev_node;
}	t_stack;

t_stack	*get_cheapest(t_stack *a);
long	ft_atol(const char *nptr);
void	init_stack_a(t_stack **a, char **argv);
void	prep_to_push(t_stack **stack, t_stack *top_node, char stack_name);
int		stack_len(t_stack *stack);
t_stack	*find_last_node(t_stack *stack);
bool	check_sorted(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);
t_stack	*find_max_node(t_stack *stack);
int	is_valid_arg(const char *arg);
int	has_duplicates(t_stack *stack, int num);
void	clean_program(t_stack **stack);

#endif /* PUSH_SWAP_H */
