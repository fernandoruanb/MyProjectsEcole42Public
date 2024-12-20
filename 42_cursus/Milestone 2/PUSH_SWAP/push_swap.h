/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:45:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2024/12/20 10:58:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
	int	count_operations;
	int	position;
}	t_stack;

char	**ft_split(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
long	ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t len);
int		ft_putstr_fd_0(const char *str, int fd);
int		ft_putstr_fd_1(const char *str, int fd);

#endif /* PUSH_SWAP_H */
