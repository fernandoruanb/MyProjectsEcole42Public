/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:05:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/27 12:55:48 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
	int		elements_b;
	int		operations;
	int		count;
	int		max_b;
	int		min_b;
}	t_stack;

int		ft_putendl_fd_0(const char *str, int fd);
int		ft_putendl_fd_1(const char *str, int fd);
char	**ft_putendl_fd_n(const char *str, int fd);
int		count_all_numbers(int argc, char **argv);
int		ft_atoi_check(const char *nptr, int *error);
int		init_stack(t_stack *stack, int total_numbers);
int		is_number(const char *str);
int		parse_args(int argc, char **argv, t_stack *stack_a);
int		is_sorted(t_stack *stack, int total_numbers, int flag);
int		is_nothing(char **str);
void	ft_sa(t_stack *stack, int flag);
void	ft_sb(t_stack *stack, int flag);
void	ft_ss(t_stack *stack);
void	ft_pb(t_stack *stack, int flag);
void	ft_pa(t_stack *stack, int flag);
void	ft_ra(t_stack *stack, int flag);
void	ft_rb(t_stack *stack, int flag);
void	ft_rr(t_stack *stack);
void	ft_rra(t_stack *stack, int flag);
void	ft_rrb(t_stack *stack, int flag);
void	ft_rrr(t_stack *stack);
int		choose_algoritm(t_stack *stack, int flag);
void	two_elements(t_stack *stack);
void	three_elements(t_stack *stack);
void	four_elements(t_stack *stack);
void	five_elements(t_stack *stack);
void	find_smallest_num(t_stack *stack, int *index);
void	six_elements(t_stack *stack);
int		move_to_b(t_stack *stack, int *local);
void	low_numbers_generic(t_stack *stack);
void	high_numbers_generic(t_stack *stack);
int		get_least_moves(t_stack *stack, int *local);
int		check_sorted(t_stack *stack);
int		check_sorted_b(t_stack *stack);
int		get_least_moves_b(t_stack *stack, int local);
void	push_all_to_a(t_stack *stack);
int	max_b_determine(t_stack *stack);
int	min_b_determine(t_stack *stack);

#endif /* PUSH_SWAP_H */
