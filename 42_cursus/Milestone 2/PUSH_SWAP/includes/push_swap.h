/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:05:30 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/22 11:02:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int		size_b;
}	t_stack;

int	ft_putendl_fd_0(const char *str, int fd);
int	ft_putendl_fd_1(const char *str, int fd);
char	**ft_putendl_fd_n(const char *str, int fd);
int	count_all_numbers(int argc, char **argv);
int	ft_atoi_check(const char *nptr, int *error);
t_stack	*initialize_stack_a(int total_numbers);
t_stack *initialize_stack_b(int total_numbers);
int	is_valid_number(const char *str);

#endif /* PUSH_SWAP_H */
